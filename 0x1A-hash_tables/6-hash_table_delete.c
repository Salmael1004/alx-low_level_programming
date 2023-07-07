#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	int i;
	hash_node_t *zero, *base;

	if (ht == NULL)
		return;

	for (i = 0; i < (int)ht->size; i++)
	{
		zero = ht->array[i];
		if (!zero)
			continue;
		while (zero)
		{
			free(zero->value);
			free(zero->key);
			base = zero->next;
			free(zero);
			zero = base;
		}
	}
	free(ht->array);
	free(ht);
}
