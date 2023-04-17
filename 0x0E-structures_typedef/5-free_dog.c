#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees the memory allocated for a dog_t variable.
 * @d: Pointer to the dog_t variable to be freed.
 */
void free_dog(dog_t *d)
{
if (d == NULL)
return;

free(d->name);
free(d->owner);

free(d);
}
