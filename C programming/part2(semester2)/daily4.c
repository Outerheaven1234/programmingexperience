/***********************************************************
Author: Vibishan Wigneswaran
Date: 2/5/2019
Effort: 30 minutes
Purpose: add new functions to further evolve daily3.c program. Create a function that can unset flags to 0.
***********************************************************/
#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[]) {

unsigned int flag_holder = 0;

 set_flag(&flag_holder, 3);
 set_flag(&flag_holder, 16);
 set_flag(&flag_holder, 31);

 display_32_flags(flag_holder);

 unset_flag(&flag_holder, 31);
 unset_flag(&flag_holder, 3);
 set_flag(&flag_holder, 9);

 display_32_flags(flag_holder);
 return 0;
}

 void set_flag(unsigned int* flag_holder, int flag_position){
    int flag;
    flag =  1 << flag_position;
    *flag_holder = *flag_holder | flag;
  }

 int check_flag(unsigned int flag_holder, int flag_position){
   int flag;
    flag = 1 << flag_position;
    int holder = flag_holder & flag;
     if(holder == 0){
      return 0;
    }
    else {
      return 1;
    }

 }

 void unset_flag(unsigned int* flag_holder, int flag_position){
   int flag;
   flag = 1 << flag_position;
   *flag_holder = *flag_holder - flag;
 }

 void display_32_flags(unsigned int flag_holder){
   int i;
   for(i=31; i>=0; i--)
   {
     printf("%d", check_flag(flag_holder, i));
     if(i%4 == 0)
     {
       printf(" ");
     }
   }
   printf("\n");
 }
