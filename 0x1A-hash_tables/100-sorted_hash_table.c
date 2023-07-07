#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
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
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *kids;
	char *onthe_block;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	onthe_block = strdup(value);
	if (onthe_block == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	kids = ht->shead;
	while (kids)
	{
		if (strcmp(kids->key, key) == 0)
		{
			free(kids->value);
			kids->value = onthe_block;
			return (1);
		}
		kids = kids->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(onthe_block);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(onthe_block);
		free(new);
		return (0);
	}
	new->value = onthe_block;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		kids = ht->shead;
		while (kids->snext != NULL && strcmp(kids->snext->key, key) < 0)
			kids = kids->snext;
		new->sprev = kids;
		new->snext = kids->snext;
		if (kids->snext == NULL)
			ht->stail = new;
		else
			kids->snext->sprev = new;
		kids->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the key value in a sorted hash table
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *zero;
	unsigned long int base;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	base = key_index((const unsigned char *)key, ht->size);
	if (base >= ht->size)
		return (NULL);

	zero = ht->shead;
	while (zero != NULL && strcmp(zero->key, key) != 0)
		zero = zero->snext;

	return ((zero == NULL) ? NULL : zero->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order
 * @ht: A pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *zero;

	if (ht == NULL)
		return;

	zero = ht->shead;
	printf("{");
	while (zero != NULL)
	{
		printf("'%s': '%s'", zero->key, zero->value);
		zero = zero->snext;
		if (zero != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print hash table in reverse order
 * @ht: pointer to hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *zero;

	if (ht == NULL)
		return;

	zero = ht->stail;
	printf("{");
	while (zero != NULL)
	{
		printf("'%s': '%s'", zero->key, zero->value);
		zero = zero->sprev;
		if (zero != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Delete hash table
 * @ht: pointer to hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *zero, *base;

	if (ht == NULL)
		return;

	zero = ht->shead;
	while (zero)
	{
		base = zero->snext;
		free(zero->key);
		free(zero->value);
		free(zero);
		zero = base;
	}

	free(head->array);
	free(head);
}
