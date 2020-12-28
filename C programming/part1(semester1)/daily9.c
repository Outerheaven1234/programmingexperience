/***********************************************
Author:	Vibishan Wigneswaran
Date:	7/15/2020
Answer to question:
If a large number is used it will still dsiplay. In the recursive example there wasnt enough memory to store each number because all 500000 numbers needed to be stored in a n instant.
Using a loop, this is not the case because the data stored in the memory is overwritten consecutivly resulting in no stack overflow.(in other words all 500000 numbers arent saved at an instance, rather a few memory blocks are overwritten over time)
  
   ***********************************************/
 #include <stdio.h>

 void loop_down_to_zero(int value);
 void loop_up_to_int(int value);

 int main(int argc, char * argv[]) {
   int n;
   printf("Please enter a positive integer: ");
   scanf("%d",&n);
   loop_down_to_zero(n);
   printf("****\n");
   loop_up_to_int(n);
   return 0;
 }

 void loop_down_to_zero(int value)
 {
    while (value>=0){
      printf("%d\n",value);
      value--;
    }
}

 void loop_up_to_int(int value)
{
  int i = 0;
    while (i<=value){
      printf("%d\n",i);
      i++;
    }
}
