#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * init_dog - Initializes a variable of type struct dog.
 * @d: Pointer to the struct dog variable to initialize.
 * @name: Pointer to the string representing the dog's name.
 * @age: The dog's age.
 * @owner: Pointer to the string representing the dog's owner.
 *
 * Return: void.
 */

void init_dog(struct dog *d, char *name, float age, char *owner) {
if (d == NULL) {
printf("Error: Null pointer passed as input.\n");
exit(1);
}
d->name = name;
d->age = age;
d->owner = owner;
}
