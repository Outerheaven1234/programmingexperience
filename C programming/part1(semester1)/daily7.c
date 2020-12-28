/***********************************************
Author: Vibishan Wigneswaran
Date: 7/15/2020
Purpose: Program uses recursion to convert decimal into binary numbers and then outputs it.
***********************************************/
#include <stdio.h>

void print_binary(int num);

int main(int argc, char * argv[])
{
    int num;
    scanf("%d", &num);
    print_binary(num);
    return 0;
}

void print_binary(int num)
{
  if(num == 1)
      printf("1");
  else if(num == 0)
      printf("0");
  else
  {
      print_binary(num/2);
      printf("%d", num%2);
  }
}
