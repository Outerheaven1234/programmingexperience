/***********************************************
Author:	Vibishan Wigneswaran
Date:	7/12/2020
Purpose: Print smile 3 times using a function
Time Spent:	5 minutes
  
   ***********************************************/
 #include <stdio.h>


void smile(void);
 int main(int argc, char *argv[]) {

     smile();
     printf("\n");
     smile();
     printf("\n");

     printf("\n");
     smile();
     return 0;

}
void smile(void)
{
    printf("  ****   \n");
    printf(" * . .* \n");
    printf("*      *\n");
    printf("*  \\_/ *\n");
    printf(" *    *\n");
    printf("  ****\n");
}
