#### REPLACE THIS COMMENT WITH YOUR NAME
	
# EECE.3170: Microprocessors I
# UMass Lowell
# Instructor: M. Geiger
    
# Question 2 for HW 2
#  (adapted from: http://www.cs.unca.edu/brock/classes/Spring2017/csci255/labs/mips32asmintro/index.html)
#
# The program below contains several comments (all of which start with ##)
#   describing an operation to be performed on one or more of the variables
#   declared at the start of the program. Replace each ## comment with *one*
#   appropriate instruction to complete the program (or, as I've done below,
#   simply move each comment to the right of the instruction)

#   When complete, the program implements the operation:
#	z = a*x*x + b*x + c

        .global    main

        .data
a:      .int       2	    # Remember, an int is a signed word (32 bits)
b:      .int       8
c:      .int       17
x:      .int       10
z:      .int       -1

        .text
        .set       noreorder
        .ent       main

main:
        lw         $t0,a	    ##	$t0 = a
	lw         $t1,b	    ##  $t1 = b
	lw	   $t2,c            ##  $t2 = c
	lw	   $t3,x            ##  $t3 = x
        mul        $t4,$t0,$t3	    ##	$t4 = a*x

##      $t4 = $t4*x
##      $t5 = b*x
        add        $t4,$t4,$t5	    ##	$t4 = $t4+$t5
##      $t4 = $t4+c
##      z = $t4
	
# This code simply loops infinitely--we'll cover jump (j) instructions soon
spin:   j          spin
        nop

       .end        main
