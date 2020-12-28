#define _CRT_SECURE_NO_WARNINGS
#include "minHeap.h"
#include "minHeap.c"
#include <stdio.h>

void clear_buffer(void);

int main(int argc, char* argv[])
{
	MIN_HEAP heap = min_heap_init_default();
	int n;
	int currentMin;
	scanf("%d", &n);
	clear_buffer();
	while (n != -1)
	{
		min_heap_insert(heap, n);
		scanf("%d", &n);
		clear_buffer();
	}
	if (min_heap_size(heap) > 0)
	{
		currentMin = min_heap_top(heap);
		printf("%d\n", min_heap_top(heap));
		min_heap_pop(heap);
	}
	while (min_heap_size(heap) > 0)
	{
		if (min_heap_top(heap) > currentMin)
			printf("%d\n", min_heap_top(heap));
		currentMin = min_heap_top(heap);
		min_heap_pop(heap);
	}

	min_heap_destroy(&heap);

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
