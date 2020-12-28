/***********************************************
Author:	Vibishan Wigneswaran
Date:	7/22/2020
Purpose: Program a rock paper scissors game that checks for proper inputs ands continues as long as the user wants
Time Spent: 45 minutes
  
   ***********************************************/
#include <stdio.h>

void duel(char player1, char player2);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[]){
  char player1, player2;
  char cont = 'Y';

  do{
  printf("Player 1 it is your turn!\nPlease enter (p)aper, (r)ock, or (s)cissors: \n");
  scanf("%c", &player1);
  clear_keyboard_buffer();
  while(player1!='R'&& player1!='r' && player1!='S' && player1!='s' && player1!='P' && player1!='p'){
    printf("I'm sorry but you must enter 'r', 'p', or 's'\n");
    scanf("%c", &player1);
    clear_keyboard_buffer();
  }

  printf("Player 2 it is your turn!\nPlease enter (p)aper, (r)ock, or (s)cissors: \n");
  scanf("%c", &player2);
  clear_keyboard_buffer();
  while(player2!='R'&& player2!='r' && player2!='S' && player2!='s' && player2!='P' && player2!='p'){
    printf("I'm sorry but you must enter 'r', 'p', or 's'\n");
    scanf("%c", &player2);
    clear_keyboard_buffer();
  }
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
void duel(char player1, char player2){

  if ((player1=='R'|| player1=='r') && (player2=='S'|| player2=='s'))
  {
    printf("Player 1 wins rock beats scissors\n");
  }
  else if ((player1=='S'|| player1=='s') && (player2=='R'|| player2=='r'))
  {
    printf("Player 2 wins rock beats scissors\n");
  }
  else if ((player1=='P'|| player1=='p') && (player2=='R'||player2=='r'))
  {
    printf("Player 1 wins Paper beats rock\n");
  }
  else if ((player1=='R'|| player1=='r') && (player2=='P'||player2=='p'))
  {
    printf("Player 2 wins Paper beats rock\n");
  }
  else if ((player1=='S'|| player1=='s') && (player2=='P'||player2=='p'))
  {
    printf("Player 1 wins scissors beats paper\n");
  }
  else if ((player1=='P'|| player1=='p') && (player2=='S'||player2=='s'))
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
