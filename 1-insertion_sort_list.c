#include "sort.h"

/**
 * insertion_sort_list - sorts a list by insertion
 * @list: list to be sorted
 * 
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;

	if (list == NULL || (*list)->next == NULL)
		return;

	temp = (*list)->next;

	while (temp != NULL)
	{
		while ((temp->prev != NULL) && (temp->prev->n > temp->n))
		{
			temp = swap_nodes(list, temp);
			print_list(*list);
		}
		temp = temp->next;
	}
}

/**
 * swap_nodes - swaps a node with its previous node
 * @list: double pointer to the head of the list
 * @node: node to be swaped with its previous one
 *
 * Return: pointer to the swaped node
 */

listint_t *swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *temp, *prev, *next;

	temp = node;
	prev = node->prev;
	next = node->next;

	prev->next = next;

	if (next != NULL)
		next->prev = prev;

	temp->prev = prev->prev;
	temp->next = prev;
	prev->prev = temp;

	if (temp->prev != NULL)
		temp->prev->next = temp;
	else
		*list = temp;

	return (temp);
}
