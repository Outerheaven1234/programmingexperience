#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>


void UserOut(double *a, double *b);
int main(int argc, char *argv[])
{
  double x, y, z;
  UserOut(&x, &y);
  printf("%d\n", x);
  printf("%d\n", y);
  //z = x+y;
  printf("The sum of the two numbers is %d\n", x + y);
  return 0;
}

void UserOut(double *a, double *b){
  printf("Enter 2 numbers seperated by a space:\n");
  scanf("%d %d", a, b);
}
