#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the head pointer of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	dlistint_t *tmp;

	if (head == NULL || *head == NULL)
		return (-1);

	/* Delete head node (index 0) */
	if (index == 0)
	{
		node = *head;
		*head = node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(node);
		return (1);
	}

	/* Traverse to target node */
	tmp = *head;
	while (index > 0 && tmp != NULL)
	{
		tmp = tmp->next;
		index--;
	}

	if (tmp == NULL)
		return (-1);

	/* Unlink and free target node */
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
