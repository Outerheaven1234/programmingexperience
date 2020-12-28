/***********************************************
Author:	Vibishan Wigneswaran
Date:	7/22/2020
Purpose: Rock paper scissors program from daily 2 but uses enums and utilizes a enum type function for player input.
Time Spent: 45 minutes
  
   ***********************************************/
#include <stdio.h>

enum choice {ROCK, PAPER, SCISSORS};

enum choice playerInput(void);
void duel(enum choice player1, enum choice player2);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[]){
  char cont = 'Y';

  do{
  printf("Player 1 it is your turn!\nPlease enter (p)aper, (r)ock, or (s)cissors: \n");
  enum choice player1 = playerInput();

  printf("Player 2 it is your turn!\nPlease enter (p)aper, (r)ock, or (s)cissors: \n");
  enum choice player2 = playerInput();


  duel(player1, player2);

  printf("Do you wish to continue? (y/n):\n");

  scanf("%c", &cont);
  clear_keyboard_buffer();
  while(cont!='Y' && cont!='y' && cont!='N'&& cont!='n'){
    printf("I'm sorry but you must enter either 'y' or 'n'\n");
    printf("Do you wish to continue? (y/n):\n");
    scanf("%c", &cont);
    clear_keyboard_buffer();
  }
  if(cont=='N'||cont=='n'){
    return 0;
  }
}while(cont=='Y'||cont=='y');
}

enum choice playerInput(void){
  char player;
  scanf("%c", &player);
  clear_keyboard_buffer();
  while(player!='R'&& player!='r' && player!='S' && player!='s' && player!='P' && player!='p'){
    printf("I'm sorry but you must enter 'r', 'p', or 's'\n");
    scanf("%c", &player);
    clear_keyboard_buffer();
  }
  if(player == 'R'||player == 'r'){
    return ROCK;
  }
  else if(player == 'P'||player == 'p'){
    return PAPER;
  }
  else{
    return SCISSORS;
  }
}

void duel(enum choice player1, enum choice player2){

  if (player1==ROCK && player2==SCISSORS)
  {
    printf("Player 1 wins rock beats scissors\n");
  }
  else if (player1==SCISSORS && player2==ROCK)
  {
    printf("Player 2 wins rock beats scissors\n");
  }
  else if (player1==PAPER && player2==ROCK)
  {
    printf("Player 1 wins Paper beats rock\n");
  }
  else if (player1==ROCK && player2==PAPER)
  {
    printf("Player 2 wins Paper beats rock\n");
  }
  else if (player1==SCISSORS && player2==PAPER)
  {
    printf("Player 1 wins scissors beats paper\n");
  }
  else if (player1==PAPER && player2==SCISSORS)
  {
    printf("Player 2 wins scissors beats paper\n");
  }
  else
  {
    printf("DRAW!\n");
  }
}

void clear_keyboard_buffer(void) {
  char ch;
  scanf("%c", &ch);
  while (ch != '\n') {
      scanf("%c", &ch);
  }
}
