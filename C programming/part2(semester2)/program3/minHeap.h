#ifndef MIN_HEAP_H
#define MIN_HEAP_H

/**********************************************************************
Program: Number Filter
Author: Peter Woislaw
Date: 3/29/2018
Time spent: 4 hours
Purpose: The purpose of this program is to order a sequence of numbers
from stdin from lowest to highest without repeats and output that
sequence
***********************************************************************/

typedef void* MIN_HEAP;

typedef struct my_heap
{
	int* data;
	int size;
	int capacity;
} My_heap;

MIN_HEAP min_heap_init_default(void);

int min_heap_top(MIN_HEAP hminHeap);

void min_heap_pop(MIN_HEAP hminHeap);

void min_heap_insert(MIN_HEAP hminHeap, int item);

void min_heap_destroy(MIN_HEAP* phminHeap);

int min_heap_size(MIN_HEAP hminHeap);
#endif