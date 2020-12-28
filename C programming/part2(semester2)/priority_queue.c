#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct priority_queue {
    int size;
    int capacity;
    int begin_index;
    int end_index;
    int *data;
}hQueue

PRIORITY_QUEUE priority_queue_init_default(void)
{
    PRIORITY_QUEUE *hQueue;
    hQueue = (PRIORITY_QUEUE *)malloc(sizeof(hQueue));
    if (hQueue != NULL)
    {
        hQueue->size = 0;
        hQueue->capacity = 10;
        hQueue->begin_index = 0;
        hQueue->end_index = 0;
        hQueue->data = (int *)malloc(sizeof(int) * hQueue->capacity);
        if (hQueue->data == NULL)
        {
            free(hQueue);
            return NULL;
        }
    }
    return hQueue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item){
  int node, parent;
    hQueue = (PRIORITY_QUEUE)malloc(sizeof(hQueue));

    if (size == hQueue->capacity)
    {
        hQueue->capacity = 1;
        hQueue->capacity += 1;
        hQueue->data = realloc(data)sizeof(int)*hQueue->capacity);
        return FAILURE;
    }
for (; node; node = parent)
    {
        parent = (node - 1) / 2;
        if (data[parent] >= data_item)
        {
            break;
        }
        data[node] = data[parent];
    }
    return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue){
  hQueue = (PRIORITY_QUEUE*)malloc(sizeof(hQueue));
    int temp;

    if ((hQueue->capacity <= (hQueue->size + 2)) && (hQueue->size > 40))
    {
        hQueue->size -= 1;
        hQueue->data = realloc(hQueue->data, sizeof(int) * hQueue->size);
        if (hQueue == NULL)
        {
            return FAILURE;
        }
    }
    temp = hQueue->data[0];
    hQueue->data[0] = temp;
    return SUCCESS
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* status){
   hQueue = (PRIORITY_QUEUE)malloc(sizeof(hQueue));
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue){
  hQueue = (PRIORITY_QUEUE)malloc(sizeof(hQueue));
   if (hQueue->capacity != 0)
   {
       return FAILURE;
   }
   while (hQueue->capacity != 0)
   {
       printf("<<%d", priority_queue_service(hQueue));
   }
   return SUCCESS;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
   PRIORITY_QUEUE* temp;
   while (phQueue != NULL)
   {
       temp = phQueue;
       phQueue = phQueue->next;
       free(temp);
       phQueue == NULL;
   }
   return;
}
