/*
Author: Vibishan Wigneswaran
Date: 7/23/2020
Purpose: Takes a start and ending number within boundaries and outputs columns with values based on the collatz conjecture and the original values.
Time Spent: 1 hour
*/

#include <stdio.h>
void clear_keyboard_buffer (void);
void HOTPO (int start, int end);

int main (int argc, char * argv[]) {
  int start, end, columnCount=0;
  printf("Enter a starting point: \n");
  scanf("%d", &start);
  clear_keyboard_buffer();
//parameters
  while (start<1 || start>1000) {
    printf("I'm sorry, the number entered must be more than 1 and less than 1000 reenter a number following these parameter: \n");
    scanf("%d", &start);
    clear_keyboard_buffer();
  }


  printf("Enter an ending point: \n");
  scanf("%d", &end);
  clear_keyboard_buffer();
//parameters
  while (end < start || start > 10000 ) {
    printf("I'm sorry, the number entered must be more than the starting point and less than 10000 reenter a number following these parameter: \n");
    scanf("%d", &end);
    clear_keyboard_buffer();
  }
  //divides columns
  for (int i = start; i <= end; i++) {
    HOTPO (i, columnCount);
    columnCount++;
    if(columnCount==7){
      printf("\n");
      columnCount=0;
    }
  }
  return 0;
}
//defines clear keyboard buffer function
  void clear_keyboard_buffer (void) {
    char ch;

    scanf("%c", &ch);

    while (ch != '\n') {
        scanf("%c", &ch);
    }
  }
  //calculates numbers for each column
    void HOTPO (int num, int columnCount) {
    int temp = num;
    int counter = 0;

    while (temp>1) {
      if (temp% 2 == 0) {
        temp = temp/2;
        counter++;
      }
      else {
        if(temp%2==1){
        temp = 3 * temp + 1;
        counter++;
      }}
    }
    printf("%5d:%-5d", num , counter);
    }
