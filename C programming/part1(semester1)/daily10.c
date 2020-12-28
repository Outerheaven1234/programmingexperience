/*
Author: Vibishan Wigneswaran
Date: 7/21/2020
Purpose:use clear_keyboard_buffer function to type negative number only
Time spent: 15 minutes
*/

#include <stdio.h>

void clear_keyboard_buffer (void);

int main (int argc, char * argv[]) {
  int n;
  printf("Please enter a negative integer: \n");
  if(scanf("%d", &n)!=1){
    clear_keyboard_buffer();
  }
  clear_keyboard_buffer();
  while (n>0){
    printf("I'm sorry, you must enter a negative integer less than zero: \n");
    scanf("%d", &n);
    clear_keyboard_buffer();
  }
  printf("The negative integer was: %d\n", n);
  return 0;
}

void clear_keyboard_buffer (void) {
  char ch;
  scanf("%c", &ch);
  while (ch != '\n') {
      scanf("%c", &ch);
  }
}
