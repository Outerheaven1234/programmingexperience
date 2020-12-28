#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>

int findSum(double arr[]);

int main(int argc, char *argv[])
{
  int sum;
  double a[10] = {
  9.9, 8.8, 7.7, 6.6, 5.5,
  4.4, 3.3, 2.2, 1.1, 1.1 };

  sum = findSum(a);
  printf("%d\n", sum);


}

int findSum(double arr[])
{
  int i = 0;
  while(1){
    if((arr[i]+arr[i+1])==arr[i+2]){
      return i;
    }
    else{
      i++;
    }
  }
}
