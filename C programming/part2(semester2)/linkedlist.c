#include <stdio.h>

typedef struct node Node;
struct node{
  int data;
  Node* next;
};

int main(int argc, char* argv[]) {
  int n = 1;
  Node* head = NULL;
  Node* temp;

}

Node* concatenate(Node* list1, Node* list2){
  node* p = NULL;
  if(list1==NULL){
    return list2;
  }
  if(list2==NULL){
    return list1;
  }
  p=list1;
  while(p->next!=NULL){
    p = p->next;
  }
  p->next=list2;
}

int Sum_iterative(Node* list1){
  Node* p = NULL;
  if(list1==NULL){
    return 1;
  }
  int n = 1;
  p = list1;
  while(p->next!=NULL){
    p=p->next;
    n++;
  }
  return n;
}

int Sum_recursive(Node* list1){
  if(list1==NULL){
    return n;
  }
  else{
    p=list1;
    p=p->next;
    n++;

    Sum_recursive(p);
  }
}

Node* destroy_recursive(Node* list1){
  Node* p = NULL;
  p = list1;
  while(p->next!=NULL){
    free(p);
    p=p->next;
  }
}

Node* insertHead(Node** list1, int item){
    Node* temp;
    temp=(Node*)malloc(sizeOf(Node));
    temp->data=item;
    temp->next=*list1;
    list1*=temp;
}

Void insertTail(Node** list1, int item){
  Node* newNode = (Node*)malloc(Node);
  newNode->data = item;

  Node* tail = *list1;
  newNode->next=NULL;
  if(*list1==NULL){
    *list1=newNode;
    return;
  }
  while(tail->next!=NULL){
    tail=tail->next;
    tail->next=newNode;
  }
}

Void insertTailr(Node** list1, int item){
  if(*list1==NULL){
    *list1=(Node*)malloc(sizeOf(Node));
    *list1->data=item;
    *list1->next=NULL;
    return;
  }
  else{
    *list1=*list1->next;
    insertTailr(&(*list1),item)
  }
}
