#include "deck.h"

/**
 * insertion_sort_by_value - sorts a deck of cards by value
 * @deck: pointer to the head of the deck
 *
 * Return: void
 */
void insertion_sort_by_value(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t *temp;

	if (deck == NULL || *deck == NULL)
		return;

	current = (*deck)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->card->value < temp->prev->card->value)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*deck = temp;
		}
		current = current->next;
	}
}

/**
 * insertion_sort_by_suit - sorts a deck of cards by suit
 * @deck: pointer to the head of the deck
 *
 * Return: void
 */
void insertion_sort_by_suit(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t *temp;

	if (deck == NULL || *deck == NULL)
		return;

	current = (*deck)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->card->kind < temp->prev->card->kind)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*deck = temp;
		}
		current = current->next;
	}
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to the head of the deck
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;

	insertion_sort_by_value(deck);
	insertion_sort_by_suit(deck);
}
