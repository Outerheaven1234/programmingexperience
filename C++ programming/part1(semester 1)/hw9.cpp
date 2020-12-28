/***********************************************
  Author: Vibishan Wigneswaran
  Date: 12/2/2019
  Purpose: Create a guessing game using object oriented programming.
  Time: 1 hour
   ***********************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//classes
class Player{
public:
  virtual int getGuess(){return 0;}
private:
  int Answer;
};

class HumanPlayer:public Player{
public:
  int getGuess(){ int x; cout<< "Enter guess: "; cin >> x; return x; }
};

class ComputerPlayer:public Player{
public:
  int getGuess(){return rand()%100;}
};

////////////////////////////////////// // Global functions given in project //////////////////////////////////////
 bool checkForWin(int guess, int answer)
 {
   if (answer == guess)
   {
     cout << "You're right! You win!" << endl;
     return true;
   }
   else if (answer < guess)
   cout << "Your guess is too high." << endl;
   else
   cout << "Your guess is too low." << endl;
   return false;
 }
 // The play function takes as input two Player objects.
 void play(Player &player1, Player &player2) {
   int answer = 0, guess = 0;
   answer = rand() % 100;
   bool win = false;
   while (!win)
   {
     cout << "Player 1's turn to guess." << endl;
     guess = player1.getGuess();
     win = checkForWin(guess, answer);
     if (win) return;
     cout << "Player 2's turn to guess." << endl;
     guess = player2.getGuess();
     win = checkForWin(guess, answer);
   }
 }

int main(int argc, char *argv[]){
  //initialize objects
  HumanPlayer player1, player2;
  ComputerPlayer cp1, cp2;

  int select;
  cout << "Welcome to the guessing came." << endl;
  cout << "Press 1 for a local game with another player."<<endl;
  cout << "Press 2 for a game against AI." << endl;
  cout << "Press 3 for a bot only game." << endl;
  cout << "Press any other key to exit." << endl;
  cin >> select;

  //choose mode
  if(select==1){
  cout << "Local Game" << endl;
  play(player1, player2);
  }
  else if(select==2){
  cout << "Game against AI" << endl;
  play(player1, cp1);
  }
  else if(select==3){
  cout << "AI Only" << endl;
  play(cp1, cp2);
  }
  else{
    cout << "Closing Game" << endl;
  }
  return 0;
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
  
   Date:	12/2/19
  
   Name:	Vibishan Wigneswaran
  
   */
