#include "lists.h"
#include <stdlib.h>

/**
 * reverse_listint - Reverses a linked list
 * @head: Pointer to pointer to the first node of the list
 *
 * Return: Pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL, *current = *head, *next;

while (current != NULL)
{
next = current->next;
current->next = prev;
prev = current;
current = next;
}

*head = prev;

return (*head);
}
