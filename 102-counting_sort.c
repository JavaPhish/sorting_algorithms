#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Implementation of the counting sort algorithm
 * @array: The array to sory
 * @size: The size of array
 *
 * Return: None (VOID)
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, iter, max = 0, compare, count = 0, sort_ind = 0, *sorted;

	if (size < 2)
		exit(1);

	/* Find highest value */
	for (iter = 0; iter < (int)size; iter++)
		if (array[iter] > max)
			max = array[iter];
	max++;

	/* Create counting array ((sizeof max) all values == 0) */
	count_array = malloc(max * sizeof(int));
	for (iter = 0; iter < max; iter++)
		count_array[iter] = 0;

	sorted = malloc(size * sizeof(int));
	/* Count each occurance of each value compared to index */
	for (iter = 0; iter < max; iter++)
	{
		for (compare = 0; compare < (int)size; compare++)
		{
			if (array[compare] == iter)
			{
				/* Count how many instances of index appear */
				count++;
				sorted[sort_ind] = array[compare];
				sort_ind++;
			}
		}
		count_array[iter] = count;
	}
	print_array(count_array, max);

	for (iter = 0; iter < (int)size; iter++)
		array[iter] = sorted[iter];

	free(sorted);
	free(count_array);
}
