#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i, j;
for (i = 0; i < 4; i++) {
  for (j = 0; j < 3; j++) {
    if (i == 2) break;
  }
}
printf("%d", i);
}
