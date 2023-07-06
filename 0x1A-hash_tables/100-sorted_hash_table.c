#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table array
 *
 * Return: A pointer to the created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    ht->shead = NULL;
    ht->stail = NULL;

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *node, *temp, *prev;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    prev = NULL;
    node = ht->array[index];

    while (node != NULL && strcmp(node->key, key) < 0)
    {
        prev = node;
        node = node->snext;
    }

    if (node != NULL && strcmp(node->key, key) == 0)
    {
        free(node->value);
        node->value = strdup(value);
        return (1);
    }

    temp = malloc(sizeof(shash_node_t));
    if (temp == NULL)
        return (0);

    temp->key = strdup(key);
    if (temp->key == NULL)
    {
        free(temp);
        return (0);
    }

    temp->value = strdup(value);
    if (temp->value == NULL)
    {
        free(temp->key);
        free(temp);
        return (0);
    }

    temp->sprev = prev;
    temp->snext = node;

    if (prev == NULL)
        ht->shead = temp;
    else
        prev->snext = temp;

    if (node == NULL)
        ht->stail = temp;
    else
        node->sprev = temp;

    if (prev == NULL)
        ht->array[index] = temp;
    else
        prev->next = temp;

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key in a sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];

    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the hash table using the sorted linked list
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    unsigned long int i;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            if (flag == 1)
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            flag = 1;
            node = node->next;
        }
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash table key/value pairs in reverse order using the sorted linked list
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    unsigned long int i;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    for (i = ht->size - 1; i < ht->size; i--)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            if (flag == 1)
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            flag = 1;
            node = node->next;
        }
        if (i == 0)
            break;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp;
    unsigned long int i;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = temp;
        }
    }

    free(ht->array);
    free(ht);
}
