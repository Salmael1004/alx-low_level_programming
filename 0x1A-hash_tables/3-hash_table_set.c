#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table data structure of hash_table_t
 * @key: the key string
 * @value: the value corresponding to the key
 * Return: 1 if it succeeded, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *zb1 = NULL, *temp = NULL;
	unsigned long int index = 0;

	if (ht == NULL || ht->array == NULL || ht->size == 0
	    || key == NULL || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup((char *)value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}

	zb1 = malloc(sizeof(zb1));
	if (zb1 == NULL)
		return (0);

	zb1->key = strdup((char *)key);
	zb1->value = strdup((char *)value);

	zb1->next = ht->array[index];
	ht->array[index] = zb1;
	return (1);
}
