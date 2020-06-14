#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - C implementation of quick sort on a normal array
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: None (VOID)
 */
void quick_sort(int *array, size_t size)
{
	if (size > 2)
		qsort_driver(array, 0, size);
}

/**
 * qsort_driver - Driver for quicksort (Lomuto scheme)
 * @array: the array to sort
 * @lo: min
 * @high: max
 *
 * Return: None (Void)
 */
void qsort_driver(int *array, int lo, int high)
{
	int part;

	if (lo < high)
	{
		part = partition(array, lo, high);
		qsort_driver(array, lo, part - 1);
		qsort_driver(array, part + 1, high);
	}
}

/**
 * partition - Lomuto partition scheme
 * @array: the array to part
 * @low: min
 * @high: max
 *
 * Return: The point of partition
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high], iter, swap;
	int i = low;

	for (iter = low; iter <= high; iter++)
	{
		if (array[iter] < pivot)
		{
			swap = array[iter];
			array[iter] = array[i];
			array[i] = swap;
			i += 1;
		}
	}
	swap = array[i];
	array[i] = array[high];
	array[high] = swap;

	return (i);
}
