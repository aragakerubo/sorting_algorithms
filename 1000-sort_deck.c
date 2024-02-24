#include "deck.h"

/**
 * get_value - gets the value of a card
 * @card: pointer to the card to get the value of
 *
 * Return: the value of the card
 */
int get_value(const card_t *card)
{
	if (card == NULL)
		return (-1);

	if (strcmp(card->value, "Ace") == 0)
		return (1);
	if (strcmp(card->value, "2") == 0)
		return (2);
	if (strcmp(card->value, "3") == 0)
		return (3);
	if (strcmp(card->value, "4") == 0)
		return (4);
	if (strcmp(card->value, "5") == 0)
		return (5);
	if (strcmp(card->value, "6") == 0)
		return (6);
	if (strcmp(card->value, "7") == 0)
		return (7);
	if (strcmp(card->value, "8") == 0)
		return (8);
	if (strcmp(card->value, "9") == 0)
		return (9);
	if (strcmp(card->value, "10") == 0)
		return (10);
	if (strcmp(card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->value, "Queen") == 0)
		return (12);
	if (strcmp(card->value, "King") == 0)
		return (13);

	return (-1);
}

/**
 * insertion_sort_by_value - sorts a deck of cards by value
 * @deck: pointer to the head of the deck
 *
 * Return: void
 */
void insertion_sort_by_value(deck_node_t **deck)
{
	deck_node_t *current, *temp;

	if (deck == NULL || *deck == NULL)
		return;

	current = (*deck)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL &&
		       get_value(temp->card) < get_value(temp->prev->card))
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*deck = temp;
		}
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
	deck_node_t *current, *temp;

	if (deck == NULL || *deck == NULL)
		return;

	current = (*deck)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && temp->card->kind < temp->prev->card->kind)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*deck = temp;
		}
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
