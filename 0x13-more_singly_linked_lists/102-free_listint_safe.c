#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely
 *
 * @h: Pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
size_t size = 0;
listint_t *current, *next;

if (!h || !(*h))
return (size);

current = *h;
*h = NULL;

while (current)
{
size++;
next = current->next;
free(current);
current = next;
if (current >= next)
{
printf("-> [%p] %d\n", (void *) current, current->n);
exit(98);
}
}

return (size);
}
