/***********************************************
	Author: Vibishan Wigneswaran
	Date: 8/2/2020

	Purpose: Create a program that uses top down approach and utilizes stub functions

	Time Spent: 5 minutes
 ***********************************************/

#include <stdio.h>

int convert_length (int num);
int convert_weight (int num);

int main(int argc, char *argv[]) {
    int choice; //stores choice
    int num;

    printf("1. convert lengths\n2. convert weights\n3. Exit\nPlease choose from (1, 2, 0):"); //initialprompt
    scanf("%d", &choice); //record prompt
while (choice != 0) {
    switch(choice) {
      case 0: break;
      //Exit
      case 1: printf("1. convert lengths \n"); scanf("%d", &choice);
      int convert_length (int num);
      case 2: printf("2. convert weights \n"); scanf("%d", &choice);
      int convert_weight (int num);
    }
}
    printf("User chose to Exit \n"); //prompt caused by exiting
    return 0;
}

int convert_length (int num) {
  printf("converts length");
  }

int convert_weight (int num) {
  printf("converts weight");
}
