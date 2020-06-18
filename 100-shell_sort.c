#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - Shell sort algorithm
 * @array: The array to sort
 * @size: THe size of the array
 *
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, iter, swap = 0, temp;

	while (gap < (int)size)
		gap = (gap * 3) + 1;

	for (; gap > 0; gap = gap / 3)
	{

		for (iter = gap; iter < (int)size; iter += 1)
		{
			swap = array[iter];

			for (temp = iter; (temp >= gap)
				&& (array[temp - gap] > swap); temp -= gap)
			{
				array[temp] = array[temp - gap];
			}

			array[temp] = swap;
		}
		if (gap < (int)size)
			print_array(array, size);
	}
}
