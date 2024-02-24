#include "sort.h"

/**
 * node_swap - swaps nodes
 * @h: pointer to head
 * @n1: pointer to node to swap
 * @n2: pointer to node to swap
 */
void node_swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * @list: pointer to be checked
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *it, *tmp, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (it = (*list)->next; it != NULL; it = tmp)
	{
		tmp = it->next;
		insert = it->prev;
		while (insert != NULL && it->n < insert->n)
		{
			node_swap(list, &insert, it);
			print_list((const listint_t *)*list);
		}
	}
}
