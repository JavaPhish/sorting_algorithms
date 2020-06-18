#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - Implementation of cocktail shaker sort
 * @list: The doubly linked list to sort
 *
 * Return: None (VOID)
 */
void cocktail_sort_list(listint_t **list)
{
	int is_sorted = 0;
	listint_t *root;

	/* I do this to make sure that list exists to begin with */
	if (!list)
		exit(1);
	root = (*list);

	while (is_sorted == 0)
	{
		is_sorted = 1;
		/* ascend the list */
		while ((*list)->next != NULL)
		{
			if ((*list)->n > (*list)->next->n)
			{
				swap_nodes((*list), (*list)->next);
				(*list) = (*list)->prev;
				while (root->prev != NULL)
					root = root->prev;
				print_list(root);
				is_sorted = 0;
			}
			(*list) = (*list)->next;
		}
		/* descend the list */
		while ((*list)->prev != NULL)
		{
			if ((*list)->n < (*list)->prev->n)
			{
				swap_nodes((*list)->prev, (*list));
				(*list) = (*list)->next;
				while (root->prev != NULL)
					root = root->prev;
				print_list(root);
				is_sorted = 0;
			}
			(*list) = (*list)->prev;
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
