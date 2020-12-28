#### REPLACE THIS COMMENT WITH YOUR NAME
	
# EECE.3170: Microprocessors I
# UMass Lowell
# Instructor: M. Geiger
    
# Question 3 for HW 2 ****SEE UPDATE BELOW FROM 9/30****
#
# The program below contains several comments (all of which start with ##)
#   describing an operation to be performed on one or more of the variables
#   declared at the start of the program. Replace each ## comment with *one*
#   appropriate instruction to complete the program (or, as I've done below,
#   simply move each comment to the right of the instruction)
	
### EACH INSTRUCTION YOU USE MUST BE A BITWISE, SHIFT, OR ROTATE INSTRUCTION

#######################
##### UPDATE 9/30 #####
#######################
# TWO OF THE "INSTRUCTIONS" LISTED BELOW ACTUALLY REQUIRE MULTIPLE INSTRUCTIONS
#  THESE LINES HAVE BEEN MARKED, AND YOU ARE ALLOWED TO USE >1 INSTRUCTION FOR
#  EACH ONE OF THE MARKED LINES (THE LINES THAT CHANGE $t0, $t1, AND $t6)

#   This program gives you some practice working with bitwise,
#     shift, and rotate operators

        .global    main

        .data
v1:	.word	12
v2:	.word	0xFEEDABEE

        .text
        .set	noreorder
        .ent	main

main:
	lw	$s1, v1		## $s1 = v1
	lw	$s2, v2		## $s2 = v2
## ***REQUIRES >1 INSTRUCTION***: $t0 = v2 with lowest 8 bits cleared (set to 0), other bits staying the same 
## ***REQUIRES >1 INSTRUCTION***: $t1 = v2 with 8 highest bits set to 1, other bits staying the same 
## $t2 = v1 multiplied by 8 *without* using a multiply instruction
## $t3 = v2 shifted so that original least-significant byte is most-significant byte of $t3 and lower bits are 0
## $t4 = v1 divided by 4 *without* using a divide instruction
## $t5 = v2 with the upper and lower half-words swapped (so result is 0xABEEFEED)
## ***REQUIRES >1 INSTRUCTION***: $t6 = v2 with middle 8 bits flipped, other bits staying the same 
	
# This code simply loops infinitely--we'll cover jump (j) instructions soon
spin:   j          spin
        nop

       .end        main