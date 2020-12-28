/**********************************************************************
Program: program1
Author: Vibishan Wigneswaran
Date:  2/15/2019
Time spent:
Purpose: Creating full program from stub functions
***********************************************************************/

#include <stdlib.h>
#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "status.h"

typedef void* BIT_FLAGS;
{
	int size;
	int capacity;
	int bit;
} Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	Bit_flags* pBit_flags;
	if (number_of_bits > 0)
	{
		pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
		if (pBit_flags != NULL)
		{
			pBit_flags->capacity = sizeof(int);
			pBit_flags->size = number_of_bits;
			pBit_flags->bit = (int*)malloc(sizeof(int));
			if (pBit_flags->bit != NULL)
			{
				*pBit_flags->bit = 0;
			}
			else
			{
				pBit_flags = NULL;
			}
		}
	}
	else
	{
		pBit_flags = NULL;
	}

	return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Status stat;
	int bit_to_set = flag_position;
	int* temp;
	Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;

	while (flag_position >= phBit_flags->capacity)
	{
//having trouble
	}

	return stat;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Status stat;
	int bit_to_set = flag_position;
	int* temp;
	Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;

	while (flag_position >= phBit_flags->capacity)
	{
    //having trouble
	}
	return stat;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	int bit
  int bit_set = flag_position;
	Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;

	if (flag_position < 0 || flag_position > phBit_flags->capacity)
		bit = -1;

	else
	{
		//still doing this part as well
	}
	return bit;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;
	return phBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flags* phBit_flags = (Bit_flags*)hBit_flags;
	return phBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	Bit_flags* pphBit_flags = (Bit_flags*)*phBit_flags;
	free(pphBit_flags->bit);
}
