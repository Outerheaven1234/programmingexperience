
#include <stdio.h>
#include <stdlib.h>

typedef void* MY_QUEUE;

typedef struct node
{
	int centimeters;
	struct node *next;
	struct node *prev;
} Node;

typedef struct queue
{
	Node* head;
	Node* tail;
} Queue;

typedef enum status { SUCCESS, FAILURE } Status;

typedef enum boolean { FALSE, TRUE } Boolean;

MY_QUEUE my_queue_init_default(void);

Status my_queue_enqueue(MY_QUEUE hQueue, int item);

Status my_queue_service(MY_QUEUE hQueue);

Boolean my_queue_empty(MY_QUEUE hQueue);

int my_queue_front(MY_QUEUE hQueue);

void my_queue_destroy(MY_QUEUE* phQueue);

void clear_buffer(void);
int process_test_case(void);

int main(int argc, char* argv[])
{
	int numCases;
	int i;

	scanf("%d", &numCases);
	clear_buffer();

	for (i = 0; i < numCases; i++)
	{
		printf("%d\n", process_test_case());
	}

	return 0;
}

void clear_buffer(void)
{
	int noc;
	char c;
	noc = scanf("%c", &c);
	while (c != '\n' && noc == 1)
		noc = scanf("%c", &c);
	return;
}

int process_test_case(void)
{
	int length;
	int remainingLength;
	int numCars;
	MY_QUEUE leftQueue;
	MY_QUEUE rightQueue;
	char ferryPosition;
	Boolean leftEmpty;
	Boolean rightEmpty;
	int numTrips;
	int i;
	int carLength;
	char carSide;

	leftQueue = my_queue_init_default();
	rightQueue = my_queue_init_default();


	scanf("%d", &length);
	scanf("%d", &numCars);
	clear_buffer();
	length *= 100;
	remainingLength = length;
	numTrips = 0;


	for (i = 0; i < numCars; i++)
	{
		scanf("%d", &carLength);
		scanf(" %c", &carSide);
		if (carSide == 'l')
		{
			my_queue_enqueue(leftQueue, carLength);
		}
		else
		{
			my_queue_enqueue(rightQueue, carLength);
		}
		clear_buffer();
	}
	leftEmpty = my_queue_empty(leftQueue);
	rightEmpty = my_queue_empty(rightQueue);

	ferryPosition = 'l';

	while (!(leftEmpty && rightEmpty))
	{
		remainingLength = length;
		numTrips++;

		if (ferryPosition == 'l')
		{
			while (!leftEmpty && remainingLength >= my_queue_front(leftQueue))
			{
				remainingLength -= my_queue_front(leftQueue);
				my_queue_service(leftQueue);
				leftEmpty = my_queue_empty(leftQueue);

			}
			ferryPosition = 'r';
		}
		else
		{
			while (!rightEmpty && remainingLength >= my_queue_front(rightQueue) )
			{

				remainingLength -= my_queue_front(rightQueue);
				my_queue_service(rightQueue);
				rightEmpty = my_queue_empty(rightQueue);

			}
			ferryPosition = 'l';
		}
	}





	return numTrips;
}


MY_QUEUE my_queue_init_default(void)
{
	Queue* pQueue;
	pQueue = (Queue*)malloc(sizeof(Queue));

	if (pQueue == NULL)
		return NULL;

	pQueue->head = NULL;
	pQueue->tail = NULL;

	return pQueue;
}

Status my_queue_enqueue(MY_QUEUE hQueue, int item)
{
	Queue* pQueue = (Queue*)hQueue;
	Node* temp = (Node*) malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}
	temp->centimeters = item;

	if (pQueue->head == NULL)
	{
		temp->next = NULL;
		temp->prev = NULL;
		pQueue->head = temp;
		pQueue->tail = temp;

	}
	else
	{
		temp->next = pQueue->tail;
		temp->prev = NULL;
		pQueue->tail->prev = temp;
		pQueue->tail = temp;
	}


	return SUCCESS;
}

Status my_queue_service(MY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	Node* temp;
	if (pQueue->head == NULL)
		return FAILURE;

	temp = pQueue->head;
	pQueue->head = pQueue->head->prev;
	free(temp);
	return SUCCESS;

}

Boolean my_queue_empty(MY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	if ((pQueue->head) == NULL)
	{

		return TRUE;
	}
	else
		return FALSE;

}

int my_queue_front(MY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	return pQueue->head->centimeters;
}

void my_queue_destroy(MY_QUEUE* phQueue)
{
	Queue* temp = *((Queue**) phQueue);
	Node* tempNode1 = temp->head;
	Node* tempNode2;
	while (tempNode1 != NULL)
	{
		tempNode2 = tempNode1;
		tempNode1 = tempNode1->next;
		free(tempNode2);
	}
	temp = NULL;
	return;
}
