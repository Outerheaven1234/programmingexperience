/***********************************************************
Author: Vibishan Wigneswaran
Date: 1/29/2019
Effort: 15 minutes
***********************************************************/
#include <stdio.h>

int main(int argc, char* argv[]) {
  int i;
  unsigned int x = 1;

   for(i = 0; x!= 0; i++){
     printf("%d:  %u\n", i, x);
     x = x<<1;
   }
   return 0;
}
