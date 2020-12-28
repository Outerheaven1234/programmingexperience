/***********************************************
Author:	Vibishan Wigneswaran
Date:	7/15/2020
Answer to Question: If the arguement inputted is too big it can result in a stack overflow by overloading the memory of the device used.
   ***********************************************/
 #include <stdio.h>
 void recursive_down_to_zero(int value);
 void recursive_up_to_int(int value);

 int main(int argc, char * argv[]) {
   int n;
   printf("Enter a positive integer: ");
   scanf("%d",&n);
   recursive_down_to_zero(n);
   printf("****\n");
   recursive_up_to_int(n);
   return 0;
 }
 void recursive_down_to_zero(int value)
 {
    if(value!=0){
      printf("%d\n",value);
      recursive_down_to_zero(value-1);
    }
    else{
      printf("%d\n",value);
    }
}
 void recursive_up_to_int(int value)
{
    if(value>=0){
      recursive_up_to_int(value-1);
      printf("%d\n",value);
    }
}
