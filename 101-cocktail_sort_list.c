#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node: pointer to the node to swap
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	swapped = 1;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->next->n < current->n)
			{
				swap_nodes(list, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
