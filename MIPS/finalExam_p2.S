/**** Vibishan Wigneswaran ****/
    
## EECE.3170: Microprocessors I
## UMass Lowell
## Instructor: M. Geiger
## finalExam_p2.S: second programming problem on Fall 2020 final exam
/*****
    MODIFICATIONS TO MAKE:
     Currently, the program doesn't do anything--it's partially configured
     to detect button presses, but it doesn't correctly handle them as written.

     You must change this program so that:
     
     - The program detects each press of S1 and S2. (If you just get the 
         buttons working and change nothing else, the ISR as written will
         toggle the LED directly above each button--LED1 for S1, LED2 for S2.)
     
     - The program changes the state of the LEDs after every *two* button
	 presses so that:
       - If only S1 is pressed twice, only LED1 turns on
	   - If only S2 is pressed twice, only LED2 turns on
	   - If each button is pressed once (order doesn't matter), both LEDs turn on
*****/
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
    
    .text		## Text section contains code
    .set noreorder	## Disable instruction reordering
    .globl main		## Define main label as a global entity
    .ent main		##   and an entry point    
    
// Including xc.h allows use of SFR names, bit masks, etc.
#include <xc.h>
    
main:
    //button press storage
    li	    s1, 0 //switch 1
    li	    s2, 0 //switch 2
    li	    s3, 2 //constant
    li	    s4, 0 //and switch
    li	    s5, 1 //constant
    /* Configure I/O ports--LEDs on Port A & C; switches on Port B */
    sw	    zero, TRISA		    ## TRISA = 0  --> all PORTA bits = output
    sw	    zero, ANSELA	    ## ANSELA = 0 --> all PORTA bits digital
    li	    t0, _PORTB_RB7_MASK
    ori	    t0, t0, _PORTB_RB13_MASK
    sw	    t0, TRISB		    ## TRISB = 0x00002080 --> pins 7 & 13 inputs
    sw	    zero, ANSELB	    ## ANSELB = 0 --> all PORTB bits digital  
    sw	    zero, TRISC		    ## TRISC = 0  --> all PORTC bits = output
    sw	    zero, ANSELC	    ## ANSELC = 0 --> all PORTC bits digital

    li	    t4, _PORTB_RB7_MASK	    ## t4 = 0x00000080 --> mask for S1
    li	    t6, _PORTB_RB13_MASK    ## t6 = 0x00002000 --> mask for S2
    
    // Configure interrupts
    lui	    t3, 0x0001			## Want INTCON bit 16 (VS<0>) = 1
					##   so vectors 8 bytes apart
    ori	    t3, t3, _INTCON_MVEC_MASK   ## Enable multivectored interrupt mode
    sw	    t3, INTCON
    
    /*** FIX INTERRUPT CONFIGURATION SO IT ACTUALLY DETECTS BUTTON INTERRUPTS ***/
   li	    t3, _IPC2_CNBIP_MASK    ## Set change notification Port B interrupt priority level to 7
    sw	    t3, IPC2SET		    ## Implicitly sets subpriority level to 0
    
    li	    t3, _IEC0_CNBIE_MASK    ## Enable Port B change 
    sw	    t3, IEC0SET		    ##    notification interrupts

    add	    t3, t4, zero	    ## Set bits in CNEN1B = 1 and CNEN0B = 0
    or	    t3, t3, t6		    ##   corresponding to switch positions
    sw	    t3, CNEN1B		    ##   (t4 = S1 bit mask; t6 = S2 bit mask)
    sw	    zero, CNEN0B	    ## Will detect falling edges on these pins
    
    li	    t3, _CNCONB_ON_MASK		    ## Enables Port B change notification
    ori	    t3, t3, _CNCONB_CNSTYLE_MASK    ## Enables edge detection
    sw	    t3, CNCONB
   /*** FINISH FIXING INTERRUPT CONFIGURATION ***/
    ei				    ## Set global interrupt enable
    
    // Main loop does nothing--interrupts detect button press, 
    //    handle LED toggling
mainloop:
    j	    mainloop
    nop
    
    .end main
    
    // Delay loop for switch debouncing
    .global delay
    .ent delay
delay:
    li	    t7, 0x61A8		    ## Set delay counter to 0x61A8 = 25,000
				    ## Since loop body has 3 instructions,
				    ##   loop takes 25,000 * 3 = 75,000
				    ##   cycles
				    ## Remaining 3 instructions take 3 cycles
				    ##  ~75,000 cycles / 8 MHz clock ~ 0.009375 sec delay
loop:
    addi    t7, t7, -1		    ## Decrement counter
    bne	    t7, zero, loop	    ##  and continue doing that until we hit 0
    nop				    
    jr	    ra
    nop

    .end delay
    
    // Handle Port B change interrupt--check switches and toggle appropriate LEDs
    .global isrvector9
    .ent isrvector9
isrvector9:   
    li	    t4, _PORTB_RB7_MASK	    ## t4 = 0x00000080 --> mask for S1
    li	    t6, _PORTB_RB13_MASK    ## t6 = 0x00002000 --> mask for S2
    
    // Check S1
    lw	    t8, CNFB
    and	    t9, t8, t4
    beq	    t9, zero, checkS2	    ## If bit 7 = 0, S1 wasn't pressed
    nop
    
    // S1 pressed--clear flag, then debounce and toggle if actually pressed
    sw	    t4, CNFBCLR		    ## Clear flag for S1
    jal	    delay		    ## Delay to debounce
    nop
    lw	    t2, PORTB		    
    and	    t2, t2, t4		    ## Is button still pressed?
    bne	    t2, zero, checkS2	    ## If not, leave LED alone and check S2
    nop
    
    /*** CHANGE THIS CODE (AND PROBABLY OTHER PARTS) TO MEET SPEC
	    AFTER YOU GET BUTTONS WORKING ***/
    addi    s1, 1
   
    // Check S2
checkS2:
    and	    t9, t8, t6
    beq	    t9, zero, intdone	    ## If bit 13 = 0, S2 wasn't pressed
    nop
    
    // S2 pressed--clear flag, then debounce and toggle if actually pressed
    sw	    t6, CNFBCLR		    ## Clear flag for S2
    jal	    delay		    ## Delay to debounce
    nop
    lw	    t2, PORTB		    
    and	    t2, t2, t6		    ## Is button still pressed?
    bne	    t2, zero, intdone	    ## If not, leave LED alone and check S2
    nop

    /*** CHANGE THIS CODE (AND PROBABLY OTHER PARTS) TO MEET SPEC
	    AFTER YOU GET BUTTONS WORKING ***/
    addi    s2, 1
    
    j	    intdone
    nop
    
    state1:
    li	    s1, 0
    li	    s2, 0
    
    li	    t0, _PORTA_RA0_MASK	    ## t0 = 0x00000001 --> control LED1
    sw	    t0, LATASET
    
    li	    t1, _PORTC_RC9_MASK	    ## t1 = 0x00000200 --> control LED2
    sw	    t1, LATCSET
    
    j	    intdone
    nop
    
    state2:
    li	    s1, 0
    li	    s2, 0
    
    li	    t0, _PORTA_RA0_MASK	    ## t0 = 0x00000001 --> control LED1
    sw	    t0, LATASET
    li	    t1, _PORTC_RC9_MASK	    ## t1 = 0x00000200 --> control LED2
    sw	    t1, LATCCLR
    
    j	    intdone
    nop
    
    state3:
    li	    s1, 0
    li	    s2, 0
    
    li	    t0, _PORTA_RA0_MASK	    ## t0 = 0x00000001 --> control LED1
    sw	    t0, LATACLR
    li	    t1, _PORTC_RC9_MASK	    ## t1 = 0x00000200 --> control LED2
    sw	    t1, LATCSET
    
    j	    intdone
    nop
    
	
    
intdone:    
    li	    t3, _IFS0_CNBIF_MASK    ## Clear Port B change notification flag
    sw	    t3, IFS0CLR		    ##    in IFS0
    
    and    s4, s1, s2
    
    beq	    s4, s5, state1
    nop
    
    beq	    s1, s3, state2
    nop
    
    beq	    s2, s3, state3
    nop
     
    //reset
    li	    s4, 0
    
    eret		    ## Return from interrupt
    .end isrvector9