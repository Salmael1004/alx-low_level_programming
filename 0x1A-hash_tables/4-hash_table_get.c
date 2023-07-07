#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table data structure of hash_table_t
 * @key: the key, string
 * Return: the value of the associated key or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *zb1 = NULL;

	if (ht == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	zb1 = ht->array[index];

	if (zb1 == NULL)
		return (NULL);

	while (zb1)
	{
		if (strcmp(zb1->key, key) == 0)
			return (zb1->value);
		zb1 = zb1->next;
	}

	return (NULL);
}
