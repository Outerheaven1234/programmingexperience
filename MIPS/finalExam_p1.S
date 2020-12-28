/**** Vibishan Wigneswaran ****/
    
## EECE.3170: Microprocessors I
## UMass Lowell
## Instructor: M. Geiger
## finalExam_p1.S: first programming problem on Fall 2020 final exam
/*****
    MODIFICATIONS TO MAKE:
     Currently, the program blinks both LEDs at the same time, and it's doing
     so at such a fast rate that you can't tell they're blinking--they appear
     to always be on. 

     You must change this program so that:
     
     - The time between Timer 1 interrupts, and therefore changes in the state
        of the LEDs, is approximately 0.75 sec.
     
     - The LEDs cycle between 8 states, returning to state 1 after leaving state 8:
	  1. LED2 on
          2. Both LEDs off
	  3. LED1 on
	  4. Both LEDs off
	  5. Both LEDs on
	  6. Both LEDs off
	  7. LED1 on
	  8. Both LEDs off
*****/
    
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
    
    // Start of text section       
    .text		## Text section contains code
    .set noreorder	## Disable instruction reordering
    .globl main		## Define main label as a global entity
    .ent main		##   and an entry point    

main:
    li	    t4, 4		    ## LED states
    li	    t5, 0		    ## interrupt trigger
    li	    t6, 0		    ## LED off state
    
    li	    s0, 4		    ## LED 2
    li	    s1, 3		    ## LED 1
    li	    s2, 2		    ## on
    li	    s3, 1		    ## LED 1
    
    // Configure port A for output
    sw	    zero, TRISA		    ## TRISA = 0  --> all PORTA bits = output
    sw	    zero, ANSELA	    ## ANSELA = 0 --> all PORTA bits digital
    sw	    zero, TRISC		    ## TRISC = 0  --> all PORTC bits = output
    sw	    zero, ANSELC	    ## ANSELC = 0 --> all PORTC bits digital
    
    // Configure Timer 1
    sw	    zero, T1CON		    ## Clear T1CON--disables timer to allow setup

    /*** 
     Desired delay is 0.75 s between interrupts
     ADD TIMER SETTINGS TO GET THE DESIRED DELAY
     ***/
    
    ori	    t1, zero, 0x5b8d	    ## Set t1 = 0x5b8d = initial PR1 value Calculations: (750 ms * 2000)/64= 23437
    sw	    t1, PR1		    ##   (maximum possible clock period--65,535 cycles)
    
    li	    t2, _IFS0_T1IF_MASK	    ## t2 = bit mask for checking Timer 1 interrupt flag
    
    li	    t3, _T1CON_TCKPS_MASK  ## Prescale by factor of 64 (TCKPS = 10)
    sw	    t3, T1CONSET
    
    // Configure interrupts
    lui	    t3, 0x0001			## Want INTCON bit 16 (VS<0>) = 1
					##   so vectors 8 bytes apart
    ori	    t3, t3, _INTCON_MVEC_MASK   ## Enable multivectored interrupt mode
    sw	    t3, INTCON
    
    li	    t3, _IPC2_T1IP_MASK	    ## Set T1 interrupt priority level to 7
    sw	    t3, IPC2		    ## Implicitly sets subpriority level to 0
    
    li	    t2, _IFS0_T1IF_MASK	    ## t2 = bit mask for checking Timer 1 interrupt flag
    sw	    t2, IEC0		    ## Enable Timer 1 interrupts (uses
				    ##   same bit mask as T1 interrupt flag)
				    
    ei				    ## Enable interrupts globally
				    
    li	    t3, _T1CON_TON_MASK	    ## Enable Timer 1 by setting "ON" bit in T1CON
    sw	    t3, T1CONSET
      
    // Main loop--whole lotta nothing, just waiting for interrupt
mainloop:
 
    beqz    t5, change_state
    nop
    
    j	mainloop
    nop
    .end main
    
    // Handle Timer1 interrupt--clear interrupt flag and toggle LED
    .global isrvector11
    .ent isrvector11
    
change_state:
    li	       t5, 1
    
    beq	       t6, s3, offState
    nop
    
    beqz       t4, reset
    nop
    
    beq        t4, s0, state1
    nop
    
    beq        t4, s1, state2
    nop
    
    beq        t4, s2, state3
    nop
    
    beq        t4, s3, state4
    nop
    
    j		mainloop
    nop
    
reset:
    li        t4, 4
    j        change_state
    nop
    
//state 1 j state 2 l1 off l2 off
state1:
    li	       t6, 1
    sw        t1, LATCSET
    addi      t4, -1
    j		mainloop
    nop
    //state 2 j state 3 l2 inv
state2:
    li	       t6, 1
    sw        t0, LATASET
    sw        t1, LATCCLR
    addi      t4, -1
    j		mainloop
    nop
    //state 3 j state 4 l1 inv l2 inv
state3:
    li	       t6, 1
    sw        t0, LATASET
    sw	      t1, LATCSET
    addi      t4, -1
    j		mainloop
    nop
    //state 4 j state 1 l2 set
state4:
    li	       t6, 1
    sw        t0, LATASET
    sw        t1, LATCCLR
    addi      t4, -1
    j		mainloop
    nop
 
offState:
    li	      t6, 0
    sw        t0, LATACLR
    sw        t1, LATCCLR
    j		mainloop
    nop
    
isrvector11:
    
    li	    t2, _IFS0_T1IF_MASK    
    sw	    t2, IFS0CLR		    ## Clear T1IF in software!
      
    /*** MODIFY THE LED BEHAVIOR TO IMPLEMENT THE 8 STATES DESCRIBED ABOVE ***/
    ## reset interrupt trigger
    li	    t5, 0
    
    li	    t0, _PORTA_RA0_MASK
    ##sw	    t0, PORTAINV
    li	    t1, _PORTC_RC9_MASK
    ##sw	    t1, PORTCINV
    
intdone:
    eret		    ## Return from interrupt
    .end isrvector11