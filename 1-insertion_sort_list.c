#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Implementation of insertion sort in doubly linked list
 * @list: The list to sort
 *
 * Return: None (Void)
 */
void insertion_sort_list(listint_t **list)
{

	/* I do this to make sure that list exists to begin with */
	if (!list)
		exit(1);

	/* I do this just to ensure im at the root node.*/
	while ((*list)->prev != NULL)
		(*list) = (*list)->prev;

	while ((*list)->next != NULL)
	{
		*list = (*list)->next;
		while ((*list)->prev != NULL && (*list)->n < (*list)->prev->n)
		{
			/* Swap the nodes if the right node is less than the left */
			swap_nodes((*list)->prev, (*list));
			/* Remember to print every swap :) */
			print_list(*list);
		}
	}
}

/**
 * swap_nodes - Swaps two linked nodes
 * @left: The left node to switch with right
 * @right: The right node to switch with left
 *
 * Return: None
 */
void swap_nodes(listint_t *left, listint_t *right)
{
	listint_t *swap_node;

	swap_node = left->prev;

	if (swap_node)
		swap_node->next = right;

	right->prev = swap_node;

	left->prev = right;
	left->next = right->next;
	right->next = left;
	if (left->next != NULL)
		left->next->prev = left;
}
