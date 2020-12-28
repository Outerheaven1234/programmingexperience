/*
Author: Vibishan Wigneswaran
Date: 7/21/2020
Purpose:use clear_keyboard_buffer function to type a number between 1-79 and output asterisks to the amount of the inputed number
Time spent: 15 minutes
*/

#include <stdio.h>

void clear_keyboard_buffer (void);
void draw_line(int x);

int main (int argc, char * argv[]) {
  int n;
  printf("Please enter the number of asterisks you want in your line: \n");
  scanf("%d", &n);
  clear_keyboard_buffer();
  while ((n<1)||(n>79)){
    printf("I'm sorry, that number is unrecognized or out of range, try [1-79]: \n");
    scanf("%d", &n);
    clear_keyboard_buffer();
  }
  draw_line(n);
  return 0;
}

void draw_line(int x){
  for(int i = 0; x!=i; i++){
    printf("*");
  }
}

void clear_keyboard_buffer (void) {
  char ch;
  scanf("%c", &ch);
  while (ch != '\n') {
      scanf("%c", &ch);
  }
}
