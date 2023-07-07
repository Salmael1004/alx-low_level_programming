#include "hash_tables.h"

/**
 * hash_table_print - prints the hash table
 * @ht: the hash table of hash_table_print
 *
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	int i;
	hash_node_t *zero;
	int base = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < (int)ht->size; i++)
	{
		zero = ht->array[i];
		if (zero == NULL)
			continue;
		if (base <= 1)
			base++;
		while (zero)
		{
			if (base == 2)
				printf(", ");
			printf("'%s': '%s'", zero->key, zero->value);
			zero = zero->next;
		}
	}
	printf("}\n");
}
