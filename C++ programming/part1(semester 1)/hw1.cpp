/***********************************************
  Author: Vibishan Wigneswaran
  Date: 9/16/19
  Purpose: Create a guessing game
  Time Spent: 45 minutes
   ***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void checkGuess(int myNum, int randnum);

int main()
{
    srand((unsigned int)time(0)); //random num gen
    int start, end, guesses, randnum, myNum, play = 1;
  while(play == 1){
    cout << "Enter starting number: " << endl;
    cin >> start;
    while(start <= 0 || start >= 1000){
      cout << "Number must be greater than 0" << endl;
      cout << "Enter starting number: " << endl;
      cin >> start;
    }
    cout << "Enter ending number: " << endl;
    cin >> end;
    while(end <= start || end >= 1000){
      cout << "Number must be greater than starting value and less than 1000" << endl;
      cout << "Enter ending number: " << endl;
      cin >> end;
    }

    cout << "Enter the number of guesses(less than 10): " << endl;
    cin >> guesses;
    while(guesses < 0 || guesses >= 10){
      cout << "Number of guesses must be less than 10 and a positive number" << endl;
      cout << "Enter the number of guesses(less than 10): " << endl;
      cin >> guesses;
    }

    randnum=(rand()%(end-1)+start);
    cout << "I have a number between "<< start << " and " << end <<". What is the number?" << endl;

    while(guesses != 0){
      cin >> myNum;
      if(myNum == randnum){
        cout << "You guessed correctly. Congratulations!!!!!!" << endl;
        break;
      }
      if(myNum != randnum){
        guesses--;
        checkGuess(myNum,randnum);
        cout << "You have " << guesses << " guesses left."<< endl;
      }
    }
    cout << "The correct number was "<< randnum <<". Do you wish to play again?(0 to end and 1 to restart)."<< endl;
    cin >> play;
  }
  cout << "game has ended" << endl;
	return 0;
}

void checkGuess(int myNum, int randnum){
  if(myNum>randnum){
    cout << "You guessed too high! Try again." << endl;
  }
  else{
    cout << "You guessed too low! Try again." << endl;
  }
}

/*
   Computing
  III
  -­‐-­‐
  COMP.2010
  Honor
  Statement
  
   The
  practice
  of
  good
  ethical
  behavior
  is
  essential
  for
  maintaining
   good
  order
  in
  the
  classroom,
  providing
  an
  enriching
  learning
   experience
  for
  students,
  and
  as
  training
  as
  a
  practicing
  computing
   professional
  upon
  graduation.
  
  This
  practice
  is
  manifested
  in
  the
   University’s
  Academic
  Integrity
  policy.
  Students
  are
  expected
  to
   strictly
  avoid
  academic
  dishonesty
  and
  adhere
  to
  the
  Academic
   Integrity
  policy
  as
  outlined
  in
  the
  course
  catalog.
  
  Violations
  will
   be
  dealt
  with
  as
  outlined
  therein.
  
   All
  programming
  assignments
  in
  this
  class
  are
  to
  be
  done
  by
  the
   student
  alone.
  
  No
  outside
  help
  is
  permitted
  except
  the
  instructor
  and
   approved
  tutors.
  
   I
  certify
  that
  the
  work
  submitted
  with
  this
  assignment
  is
  mine
  and
  was
   generated
  in
  a
  manner
   consistent
  with
  this
  document,
  the
  course
   academic
  policy
  on
  the
  course
  website
  on
  Blackboard,
  and
  the
  UMass
   Lowell
  academic
  code.
  
   Date:	9/16/19
  
   Name:	Vibishan Wigneswaran
  
   */
