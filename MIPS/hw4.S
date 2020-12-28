## EECE.3170: Microprocessors I
## UMass Lowell
## Instructor: M. Geiger
## homework 4 assignment
## Vibishan Wigneswaran
## 01792999
## 11/9/2020
           
    .text		## Text section contains code
    .set noreorder	## Disable instruction reordering
    .globl main		## Define main label as a global entity
    .ent main		##   and an entry point    

#include <xc.h>
    
main:
    sw	    zero, TRISA		    ## TRISA = 0  --> all PORTA bits = output
    sw	    zero, ANSELA	    ## ANSELA = 0 --> all PORTA bits digital
    not	    t0, zero		    
    sw	    t0, TRISB
    sw	    zero, ANSELB
    sw	    zero, TRISC
    sw	    zero, ANSELC
    li	    t0, _PORTA_RA0_MASK	    ## $t0 = 0x00000001
    li	    t2, _PORTC_RC9_MASK
    li	    t5, _PORTB_RB7_MASK	    ## t5 = 0x00000080 --> saved state of S1
    li	    t6, _PORTB_RB13_MASK    ## t6 = 0x00002000 --> saved state of S2
    sw	    t0, LATASET		    ## Set Port A, bit 0 (turn LED1 on)
    sw	    t2, LATCSET
    li	    t7, 4		    ## stores state
    li	    s0, 4		    ## simultaneous
    li	    s1, 3		    ## alternative
    li	    s2, 2		    ## pause led 2
    li	    s3, 1		    ## pause led 1
    li	    s4, 1		    ## constant
    li	    s5, 0		    ## constant
    
toggle:
    li	    t1, 0x00150000	    ## Set delay counter .5 seconds
				    			    
delay:
    addi    t1, t1, -1		    ## Decrement counter
    bne	    t1, zero, delay	    ##  and continue doing that until we hit 0
    nop

pbutton:    ##pause
    lw	    t3, PORTB
    and	    t4, t3, t5
    bne	    t4, t5, rest
    nop
    beq	    t5, s3, pbutton
    nop
    j	    button
    nop
    
button:
    lw	    t3, PORTB	    ## if button on pause   
    and	    t4,	t3, t6	    ## if button 2 change state
    bne	    t4, zero, change_state
    nop
    j	    state
    nop
    
state:
    addi    t7, -1
     
change_state:
    beqz    t7, reset
    nop
    
    beq	    t7, s0, blink
    nop
    
    beq	    t7, s1, blink1
    nop
    
    beq	    t7, s2, blink2
    nop
    
    beq	    t7, s3, blink3
    nop

reset:
    li	    t7, 4
    j	    change_state
    
blink:
    sw	    t0, LATAINV
    sw	    t2, LATCINV
    j	    toggle		    ## Reset delay counter and start again
    nop

blink1:
    beq	    s3, s4, alternate
    nop
    
    sw	    t0, LATAINV
    sw	    t2, LATCINV
    j	    toggle
    nop

blink2:
    beqz    s4,	falt
    nop
    
    sw	    t2, LATCINV		    ## LED1 PAUSE
    j	    toggle
    nop

blink3:	
    sw	    t0, LATAINV		    ## LED2 PAUSE
    j	    toggle 
    nop

alternate:
    sw	    t0, LATACLR		    ## alternate
    sw	    t2, LATCSET
    li	    s4, 0
    j	    toggle
    nop

falt:				    ##fix alternate
    li	    s4, 1
    j	    toggle
    nop

rest:
    lw	    t3, PORTB	    ## if button on pause
    and	    t4,	t3, t5
    bne	    t4, zero, rest
    nop
    j	    pbutton
    nop
    
spin:
    j	spin
    nop

    .end main