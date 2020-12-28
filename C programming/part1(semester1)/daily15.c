/***********************************************
	Author: Vibishan Wigneswaran
	Date: 8/2/2020

	Purpose: Create a program that uses top down approach and utilizes stub functions. Previous stub functions are implemented.

	Time Spent: 20 minutes
 ***********************************************/

#include <stdio.h>

int convert_length (int num);
int convert_weight (int num);
int length_to_us (int num);
int length_to_metric (int num);
int weight_to_us (int num);
int weight_to_metric (int num);

int main(int argc, char *argv[]) {
    int choice; //stores choice
    int num = 0;

    printf("1. convert lengths\n2. convert weights\n0. Exit\nPlease choose from (1, 2, 0):"); //initialprompt
    scanf("%d", &choice); //record prompt
while (choice != 0) {
    switch(choice) {
      case 0: break;
      //Exit
      case 1: printf("1. convert lengths \n\n"); convert_length(num); printf("1. convert lengths\n2. convert weights\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice);
      case 2: printf("2. convert weights \n\n"); convert_weight(num); printf("1. convert lengths\n2. convert weights\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice);
    }
}
    printf("User chose to Exit \n\n"); //prompt caused by exiting
    return 0;
}

int convert_length (int num) {
  int choice;
  printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); //initialprompt
  scanf("%d", &choice); //record prompt
while (choice != 0) {
  switch(choice) {
    case 0: break;
    //Exit
    case 1: printf("1. convert to metric \n\n"); length_to_metric(num); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice);
    case 2: printf("2. convert to us \n\n"); length_to_us(num); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice);
  }
}
  printf("User chose to Exit \n\n");
  }

int convert_weight (int num) {
  int choice;
  printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); //initialprompt
  scanf("%d", &choice); //record prompt
while (choice != 0) {
  switch(choice) {
    case 0: break;
    //Exit
    case 1: printf("1. convert to metric \n\n"); weight_to_metric(num); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice);
    case 2: printf("2. convert to us \n\n"); weight_to_us(num); printf("1. convert to metric\n2. convert to US\n0. Exit\nPlease choose from (1, 2, 0):"); scanf("%d", &choice);
  }
}
}
int length_to_us (int num) {
  printf("converts length to US\n\n");
}

int length_to_metric (int num) {
  printf("converts length to metric\n\n");
}

int weight_to_us (int num) {
  printf("converts weight to us\n\n");
}

int weight_to_metric (int num) {
  printf("converts weight to metric\n\n");
}
