## EECE.3170: Microprocessors I
## UMass Lowell
## Instructor: M. Geiger
## Homework 5 
## Vibishan WIgneswaran
    
// Including xc.h allows use of SFR names, bit masks, etc.
#include <xc.h>
    
    // Interrupt vector setup    
    .globl  __vector_dispatch_11    ## Timer 1 interrupt = vector #11
    .section .vector_11, code, keep
    .align 2
    .set nomips16
    .ent __vector_dispatch_11
    
__vector_dispatch_11:
    j  isrvector11	    ## Jump to actual ISR code, which is in text section
    nop
    .end __vector_dispatch_11
    .size __vector_dispatch_11, .-__vector_dispatch_11
    
    // Interrupt vector setup    
    .globl  __vector_dispatch_9    ## Port B change notification = vector #9
    .section .vector_9, code, keep
    .align 2
    .set nomips16
    .ent __vector_dispatch_9
    
__vector_dispatch_9:
    j  isrvector9	    ## Jump to actual ISR code, which is in text section
    nop
    .end __vector_dispatch_9
    .size __vector_dispatch_9, .-__vector_dispatch_9
    
    // Start of text section       
    .text		## Text section contains code
    .set noreorder	## Disable instruction reordering
    .globl main		## Define main label as a global entity
    .ent main		##   and an entry point    

main:
    // set necessary registers
    li	    t7, 4 //states
    li	    s0, 4		    ## simultaneous
    li	    s1, 3		    ## alternative
    li	    s2, 2		    ## pause led 2
    li	    s3, 1		    ## pause led 1
    li	    s4, 0		    ## constant
    li	    s6, 0x0FFF		    ## delay states
    li	    s7, 0xFFF0		    ## delay states
    
    // Configure port A for output
    sw	    zero, TRISA		    ## TRISA = 0  --> all PORTA bits = output
    sw	    zero, ANSELA	    ## ANSELA = 0 --> all PORTA bits digital
    li	    t0, _PORTA_RA0_MASK	    ## $t0 = 0x00000001    
    //sw	    t0, LATASET		    ## Set Port A, bit 0 (turn LED1 on)
    
    // Configure port C for output
    sw	    zero, TRISC
    sw	    zero, ANSELC
    li	    t4, _PORTC_RC9_MASK
    //sw	    t4, LATCSET
    // Configure port B
    li	    t5, _PORTB_RB7_MASK
    ori	    t5, t5, _PORTB_RB13_MASK
    sw	    t5, TRISB		    ## TRISB = 0x00002080 --> pins 7 & 13 inputs
    sw	    zero, ANSELB	    ## ANSELB = 0 --> all PORTB bits digital  
    
    //li	    t5, _PORTB_RB7_MASK	    ## t4 = 0x00000080 --> mask for S1
    li	    t6, _PORTB_RB13_MASK    ## t6 = 0x00002000 --> mask for S2
    // Configure Timer 1
    sw	    zero, T1CON		    ## Clear T1CON--disables timer to allow setup
    
    ori	    t1, zero, 0x0FFF	    ## Set t1 = 0xFFFF = initial PR1 value
    sw	    t1, PR1		    ##   (maximum possible clock period--65,535 cycles)
    
    li	    t2, _IFS0_T1IF_MASK	    ## t2 = bit mask for checking Timer 1 interrupt flag
    
    ## Prescale clock
    li	    t3, _T1CON_TCKPS_MASK  ## Prescale by factor of 64 (TCKPS = 10)
    sw	    t3, T1CONSET
    
    // Configure interrupts
    lui	    t3, 0x0001			## Want INTCON bit 16 (VS<0>) = 1
					##   so vectors 8 bytes apart
    ori	    t3, t3, _INTCON_MVEC_MASK   ## Enable multivectored interrupt mode
    sw	    t3, INTCON
    
    li	    t3, _IPC2_T1IP_MASK	    ## Set T1 interrupt priority level to 7
    sw	    t3, IPC2		    ## Implicitly sets subpriority level to 0
    
    sw	    t2, IEC0		    ## Enable Timer 1 interrupts (uses
				    ##   same bit mask as T1 interrupt flag)
				    
    				    ## Enable interrupts globally
				    
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONSET
    
    //configure switch interrupt
    
   
    li	    t3, _IPC2_CNBIP_MASK    ## Set change notification Port B interrupt priority level to 7
    sw	    t3, IPC2SET		    ## Implicitly sets subpriority level to 0
    
    li	    t3, _IEC0_CNBIE_MASK    ## Enable Port B change 
    sw	    t3, IEC0SET		    ##    notification interrupts

    add	    t3, t5, zero	    ## Set bits in CNEN1B = 1 and CNEN0B = 0
    or	    t3, t3, t6		    ##   corresponding to switch positions
    sw	    t3, CNEN1B		    ##   (t4 = S1 bit mask; t6 = S2 bit mask)
    sw	    zero, CNEN0B	    ## Will detect falling edges on these pins
    
    li	    t3, _CNCONB_ON_MASK		    ## Enables Port B change notification
    ori	    t3, t3, _CNCONB_CNSTYLE_MASK    ## Enables edge detection
    sw	    t3, CNCONB
    
    ei				    ## Set global interrupt enable


    // Main loop--whole lotta nothing, just waiting for interrupt
mainloop:
    beqz    s4, change_state
    nop
    
    j	mainloop
    nop
    .end main
    
    
    // Handle Timer1 interrupt--clear interrupt flag and toggle LED
    .global isrvector11
    .ent isrvector11

change_state:
    li	       s4, 1
    
    beqz       t7, reset
    nop
    
    beq        t7, s0, state1
    nop
    
    beq        t7, s1, state2
    nop
    
    beq        t7, s2, state3
    nop
    
    beq        t7, s3, state4
    nop
    
    j		mainloop
    nop
    
reset:
    li        t7, 4
    j        change_state
    
//state 1 j state 2 l1 off l2 off
state1:
    sw        t4, LATCSET
    addi      t7, -1
    j		mainloop
    nop
    //state 2 j state 3 l2 inv
state2:
    sw        t0, LATASET
    sw        t4, LATCCLR
    addi      t7, -1
    j		mainloop
    nop
    //state 3 j state 4 l1 inv l2 inv
state3:
    sw        t0, LATASET
    sw	      t4, LATCSET
    addi      t7, -1
    j		mainloop
    nop
    //state 4 j state 1 l2 set
state4:
    sw        t0, LATACLR
    sw        t4, LATCCLR
    addi      t7, -1
    j		mainloop
    nop
 
    //S1 delay *2
    
isrvector9:
    li	    t5, _PORTB_RB7_MASK	    ## t5 = 0x00000080 --> mask for S1
    li	    t6, _PORTB_RB13_MASK    ## t6 = 0x00002000 --> mask for S2
	   
switch:    ##increase
    lw	    t8, CNFB
    and	    t9, t8, t5
    beq	    t9, zero, switch2	    ## If bit 7 = 0, S1 wasn't pressed
    nop
    
    sw	    t5, CNFBCLR
    
    lw	    s5, PORTB
    and	    s5, s5, t5
    bne	    s5, zero, switch2
    nop
 
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONCLR
    sll	    t1, t1, 1
    sw	    t1, PR1
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONSET
    
    bgt	    t1, s7, MaxDelay
    nop
    
    j	    switch2
    nop
    
    
switch2:  ##decrease
    lw	    t8, CNFB
    and	    t9, t8, t6
    beq	    t9, zero, done
    nop
    
    sw	    t6, CNFBCLR
    
    lw	    s5, PORTB
    and	    s5, s5, t6
    bne	    s5, zero, done
    nop
    
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONCLR
    srl	    t1, t1, 1
    sw	    t1, PR1
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONSET
    
    blt	    t1, s6, MinDelay
    nop
    
    j	    done
    nop
    

done: 
    li	    t3, _IFS0_CNBIF_MASK    ## Clear Port B change notification flag
    sw	    t3, IFS0CLR		    ##    in IFS0
    eret
    
MinDelay:
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONCLR
    ori	    t1, zero, 0xFFF0
    sw	    t1, PR1
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONSET
    
    j	    done
    nop
    
MaxDelay:
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONCLR
    ori	    t1, zero, 0x0FFF
    sw	    t1, PR1
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONSET
    
    j	    done
    nop
    
    //.end isrvector9
    //S2 delay /2
    //555 timer setup
isrvector11:
    li	    s4, 0
    li	    t2, _IFS0_T1IF_MASK    
    sw	    t2, IFS0CLR		    ## Clear T1IF in software!
    li	    t0, _PORTA_RA0_MASK	    ## $t0 = 0x00000001  
    li	    t4, _PORTC_RC9_MASK
    
eret		    ## Return from interrupt
    .end isrvector11
    
    

