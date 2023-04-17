#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - Creates a new dog_t variable.
 * @name: Pointer to the string representing the dog's name.
 * @age: The dog's age.
 * @owner: Pointer to the string representing the dog's owner.
 *
 * Return: Pointer to the newly created dog_t variable, or NULL if the
 *         function fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog = malloc(sizeof(dog_t));

if (new_dog == NULL)
return (NULL);

new_dog->name = malloc(sizeof(char) * (strlen(name) + 1));
new_dog->owner = malloc(sizeof(char) * (strlen(owner) + 1));

if (new_dog->name == NULL || new_dog->owner == NULL)
{
free(new_dog->name);
free(new_dog->owner);
free(new_dog);
return (NULL);
}

strcpy(new_dog->name, name);
strcpy(new_dog->owner, owner);

new_dog->age = age;

return (new_dog);
}
