#include <stdio.h>
#include <stdlib.h>
#include "minHeap.h"

void trickle_down(My_heap* pHeap, int index);

MIN_HEAP min_heap_init_default(void)
{
	My_heap* pHeap = (My_heap*)malloc(sizeof(My_heap));
	if (pHeap == NULL)
	{
		return NULL;
	}
	else
	{
		pHeap->data = (int*)malloc(sizeof(int) * 255);
		if (pHeap->data == NULL)
		{
			free(pHeap);
			return NULL;
		}
		else
		{
			pHeap->size = 0;
			pHeap->capacity = 255;
			return (MIN_HEAP)pHeap;
		}
	}
}
int min_heap_top(MIN_HEAP hminHeap)
{
	My_heap* pHeap = (My_heap*)hminHeap;
	if (pHeap->size > 0)
		return pHeap->data[0];
	else
		return -1;
}
void min_heap_pop(MIN_HEAP hminHeap)
{
	My_heap* pHeap = (My_heap*)hminHeap;

	if (pHeap->size > 0)
	{
		pHeap->data[0] = pHeap->data[(pHeap->size) - 1];

		pHeap->size--;
		trickle_down(pHeap, 0);


	}
}
void min_heap_insert(MIN_HEAP hminHeap, int item)
{
	My_heap* pHeap = (My_heap*)hminHeap;

	if (pHeap->size >= pHeap->capacity)
	{
		int i;
		int* temp = NULL;
		temp = (int*)malloc(sizeof(int)*pHeap->capacity * 2);
		if (temp == NULL)
			return;

		else
		{
			for (i = 0; i < pHeap->size; i++)
			{
				temp[i] = pHeap->data[i];
			}
			free(pHeap->data);
			pHeap->data = temp;
		}
	}

	pHeap->data[pHeap->size] = item;
	int childIndex = pHeap->size;
	int parentIndex = (childIndex - 1) / 2;

	while (childIndex > 0 && pHeap->data[parentIndex] > pHeap->data[childIndex])
	{
		int tempInt = pHeap->data[parentIndex];
		pHeap->data[parentIndex] = pHeap->data[childIndex];
		pHeap->data[childIndex] = tempInt;

		childIndex = parentIndex;
		parentIndex = (childIndex - 1) / 2;
	}
	pHeap->size++;
}

void min_heap_destroy(MIN_HEAP** phminHeap)
{
	My_heap* pHeap = (My_heap*)*phminHeap;
	free(pHeap->data);
	free(pHeap);
	*phminHeap = NULL;
}

void trickle_down(My_heap* pHeap, int index)
{
	int leftInd = (index * 2) + 1;
	int rightInd = (index * 2) + 2;
	if (leftInd >= pHeap->size)
		return;
	else if (rightInd >= pHeap->size)
	{
		if (pHeap->data[index] > pHeap->data[leftInd])
		{
			int temp = pHeap->data[index];
			pHeap->data[index] = pHeap->data[leftInd];
			pHeap->data[leftInd] = temp;
			trickle_down(pHeap, leftInd);
		}
	}
	else
	{
		if (pHeap->data[rightInd] < pHeap->data[leftInd])
		{
			if (pHeap->data[index] > pHeap->data[rightInd])
			{
				int temp = pHeap->data[index];
				pHeap->data[index] = pHeap->data[rightInd];
				pHeap->data[rightInd] = temp;
				trickle_down(pHeap, rightInd);

			}
		}
		else
		{
			if (pHeap->data[index] > pHeap->data[leftInd])
			{
				int temp = pHeap->data[index];
				pHeap->data[index] = pHeap->data[leftInd];
				pHeap->data[leftInd] = temp;
				trickle_down(pHeap, leftInd);
			}
		}
	}
	return;
}

int min_heap_size(MIN_HEAP hminHeap)
{
	My_heap* pHeap = (My_heap*)hminHeap;

	return pHeap->size;
}
