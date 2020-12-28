/***********************************************
   Author:	Vibishan Wigneswaran
   Date: 8/2/2020
  
   Purpose:	Crud population calculator
   Time Spent: 45 minutes
***********************************************/
#include <stdio.h>

int crudCalc(int initial, int days);
void clear_keyboard_buffer(void);

int main(int argc, char * argv[]) {
  int initial;
  int days;
  int final;
  char ans;

do {
  printf("Please enter the intial size of the green crud: \n");
  scanf("%d",&initial);
  clear_keyboard_buffer();

  while(initial < 0 || initial >= 'a' || initial >= 'A'){
    printf("I'm sorry that value is unrecognized or is negative. \n");
    scanf("%d",&initial);
    clear_keyboard_buffer();
  }
    printf("Please enter the number of days: \n");
    scanf("%d", &days);
    clear_keyboard_buffer();

    while(days < 0 || days >= 'a' || days >= 'A'){
      printf("I'm sorry that value is unrecognized or is negative. \n");
      scanf("%d",&days);
      clear_keyboard_buffer();
    }

    final = crudCalc(initial, days);
    printf("With an initial population of %d pounds of crud growing for %d days. \nThe final population would be %d pounds\n", initial, days, final);
    printf("Would you like to continue? (y/n):\n");
    scanf("%c", &ans);
    clear_keyboard_buffer();

    while(ans!='Y' && ans!='y' && ans!='N' && ans!='n'){
      printf("I'm sorry but you must enter either 'y' or 'n'\n");
      printf("Would you like to continue? (y/n):\n");
      scanf("%c", &ans);
      clear_keyboard_buffer();
    }
    if(ans=='N'||ans=='n'){
      return 0;
    }
}while(ans=='Y'||ans=='y');
}

int crudCalc(int initial, int days)
{
  double n = (days/5) , x = initial, y = 0, next, c, result;
  //if n is a fraction if-statement adjusts its value
  if(n < 1){
    n = 1;
  }
   for (c=0; c < n; c++) {
     next = y + x;
     y = x;
     x = next;
    }
    result = next;
    return result;
  }

  void clear_keyboard_buffer(void) {
    char ch;
    scanf("%c", &ch);
    while (ch != '\n') {
        scanf("%c", &ch);
    }
  }
