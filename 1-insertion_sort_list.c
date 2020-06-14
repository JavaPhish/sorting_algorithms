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
	listint_t *root;
	/* I do this to make sure that list exists to begin with */
	if (!list)
		exit(1);

	/* I do this just to ensure im at the root node.*/
	while ((*list)->prev != NULL)
		(*list) = (*list)->prev;

	root = (*list);

	while ((*list)->next != NULL)
	{
		*list = (*list)->next;
		while ((*list)->prev != NULL && (*list)->n < (*list)->prev->n)
		{
			/* Swap the nodes if the right node is less than the left */
			swap_nodes((*list)->prev, (*list));

			/**
			 * Roots node gets changed with swap every now and then
			 * so we have to re-iterate back to root b4 we print to
			 * make sure the entire list gets printed (because they gave
			 * us a dumb print function that doesnt navigate to root on
			 * its own.)
			 */
			while (root->prev != NULL)
				root = root->prev;
			print_list(root);
			/* Remember to print every swap :) */
		}
	}

	/* Navigate the list back to root in case they try to print it */
	while ((*list)->prev != NULL)
		(*list) = (*list)->prev;
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
