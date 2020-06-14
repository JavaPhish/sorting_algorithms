#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Implementation of selection sort with normal arrays
 * @size: The size of the array to sort
 * @array: The array to sort
 *
 * Return: None (Void)
 */
void selection_sort(int *array, size_t size)
{
	int swap, list_iter, min, head;

	/* Loop through the entire array. */
	for (list_iter = 0; list_iter < (int)size; list_iter++)
	{
		/* Min stores the INDEX of the smallest value found (NOT THE VALUE!!) */
		min = list_iter;

		/* Find the min value within the shrinking window */
		for (head = list_iter; head < (int)size; head++)
			if (array[head] < array[min])
				min = head;

		/* Check if the min value was changed, if so SWAP IT AND PRINT IT! */
		if (min != list_iter)
		{
			swap = array[list_iter];
			array[list_iter] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}
