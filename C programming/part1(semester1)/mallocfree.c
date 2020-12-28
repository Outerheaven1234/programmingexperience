#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node Node;
struct Node{
  int data;
  Node head*;
};

int main(int argc, char *argv[])
{
  Node* head;
  head = (Node*)malloc(sizeof(Node));
  (*head).data=5;
  head->next;
  return 0;
}
