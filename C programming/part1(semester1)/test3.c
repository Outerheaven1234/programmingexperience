#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int buff, n;

  FILE *fp_input, *fp_output;
  fp_input=fopen("input.txt","r");
  fp_output=fopen("output.txt","w");

  while((fscanf(fp_input, "%d", & buff))!=EOF){
    printf("%d ", buff);
    fprintf(fp_output, "%d\n", abs(buff));
  	++n;
  }

  return 0;
}
