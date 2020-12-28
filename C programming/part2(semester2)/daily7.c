/**********************************************************************
Program: daily7.c
Author: Vibishan Wigneswaran
Date:  2/22/2019
Time spent: <total amount of time spent on the project>
Purpose: A program that checks to see if parenthesis are used properly
***********************************************************************/

#include <stdio.h>

void stringCheck(char str[], int size);
int lengthString(char str[], int size);

int main(int argc, char *argv[]) {
    char str[];
    int size;

    size = lengthString(str[]);
    stringCheck(str[], size);

    return 0;
}

// function definition to make sure string follows the parenthesis rule
void stringCheck(char str[], int size){
  int i;
  int parenth;

  for(i = 0; i <= size; i++){
    if(string[i]=='{'||'}'){
      parenth++;
    }
    if(string[i]=='('||')'){
      parenth++;
    }
    if(string[i]=='['||']'){
      parenth++;
    }
  }
  if(parenth/2==1){
    printf("yes");
  }
  else{
    printf("no");
  }
}

int lengthString(char str[]){
  int i = 0;
  int length = 0;
  while(str[i] != EOF){
    length++;
    i++;
  }
  return length;
}
