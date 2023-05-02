#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a linked list of integers
 * @head: pointer to the head node of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *p1, *p2;
size_t count = 0;

if (head == NULL)
exit(98);

p1 = head;
p2 = head->next;

while (p2 != NULL && p2 < p1)
{
printf("[%p] %d\n", (void *)p1, p1->n);
count++;
p1 = p1->next;
p2 = p2->next;
}

printf("[%p] %d\n", (void *)p1, p1->n);
count++;

if (p2 != NULL)
{
printf("-> [%p] %d\n", (void *)p2, p2->n);
count++;
}

while (p2 != NULL && p2 > p1)
{
printf("[%p] %d\n", (void *)p2, p2->n);
count++;
p1 = p1->next;
p2 = p2->next;
}

if (p2 != NULL)
exit(98);

return (count);
}
