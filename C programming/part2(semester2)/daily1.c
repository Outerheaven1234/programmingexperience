/***********************************************************
Author: Vibishan Wigneswaran
Date: 2/6/2019
Try #2 the issue was my for loop
***********************************************************/
#include <stdio.h>

char* reverse(char word[]);

int main(int argc, char* argv[]) {
   char word[] = "Happy Birthday!";

   printf("%s\n", word);
   reverse(word);
   printf("%s\n", word);
   printf("%s\n", reverse(word));
   printf("%s\n", word);
   return 0;
}

char* reverse(char word[]){
  int n, i, size;
  char temp;
  n=0;
  while(word[n]!='\0'){
    n++;
    }
  size = n;
  for(i = 0; i <= (size-1)/2; i++){

    temp = word[i];
    word[i] = word[size-1-i];
    word[size-1-i] = temp;
  }
  return word;
}
