/**********************************************************************
Program: daily6
Author: Vibishan Wigneswaran
Date:  2/10/2019
Time spent:
Purpose:
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

void reverse(Node* head);


int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node).
  reverse(&head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

//Define your function here

void reverse(Node* head){
	struct Node* prev   = NULL;
  struct Node* temp = *head;
  struct Node* next = NULL;
  while (temp != NULL) {
        // Store next
        next  = temp->next;

        // Reverse next node's pointer
        temp->next = prev;

        // Move pointers one position ahead.
        prev = temp;
        temp = next;
    }
    head = prev;
}
