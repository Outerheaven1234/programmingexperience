#include <stdio.h>
//retreives stdio.h


char reverse(char word[]);

//Main statement should be here

//definition for reverse function
char reverse(char word[]){
  int n, i, size;
  char temp;
  n=0;

  //finds length of string
  while(word[n]!='\n'){
    n++;
    }

  //sets size to length of sting
  size = n;

  // reverses string
  for(i = 0; i <= size/2; i++){
    temp = word[i];
    word[i] = word[size-i];
    word[size-i] = temp;
  }
}
