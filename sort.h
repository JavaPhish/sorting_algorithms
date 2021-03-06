#ifndef SORT_H
#define SORT_H

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

/* Helper functions/tools */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void swap_nodes(listint_t *left, listint_t *right);
void qsort_driver(int *array, int lo, int high);
int partition(int *array, int low, int high);

#endif
