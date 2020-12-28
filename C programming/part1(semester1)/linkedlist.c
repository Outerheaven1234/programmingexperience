#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node;

typedef struct node Node;

struct node{
  int data;
  Node* next;
};

int main(int argc, char *argv[])
{
  Node* head;
  Node* temp;
  head = (Node*)malloc(sizeof(Node));
  if(head==NULL){
    printf("failed to allocated\n");
    exit(1);
  }
  (*head).data = 42;
  head->next = NULL; //-> dereference head and next at the same time
  temp = head;

  (*head).data = 32;
  head->next = NULL; //-> dereference head and next at the same time
  temp = head;

  while(temp!=NULL){
    printf("%d\n", temp->data);
    temp = temp->next;
  }
  return 0;
}
