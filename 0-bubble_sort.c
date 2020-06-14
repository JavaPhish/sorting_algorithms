#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * bubble_sort - Implemenation of the bubble sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: The sorted array
 */
void bubble_sort(int *array, size_t size)
{
	int swap, head, tail, swap_count = 1;

	/* If the array is too small to sort it will just bypass the while */
	if (size < 2)
	{
		swap_count = 0;
	}

	/* One loop in the while is considered a single pass */
	while (swap_count != 0)
	{
		/* If no swaps were made, the array is sorted */
		/* a swap is only made when two items are out of place */
		swap_count = 0;
		for (head = 1; head < (int)size; head++)
		{
			tail = head - 1;

			if (array[tail] > array[head])
			{
				swap = array[tail];
				array[tail] = array[head];
				array[head] = swap;
				/* Prints the array every time it swaps any values */
				print_array(array, size);
				swap_count++;
			}
		}
	}
}
