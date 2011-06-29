#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "hash.h"

#define HASHSIZE 19

#define TRUE 1
#define FALSE 0

unsigned int ELFHash(const char *str, unsigned int len)
{
	unsigned int hash = 0;
	unsigned int x = 0;
	unsigned int i = 0;
	for (i = 0; i < len; str++, i++) {
		hash = (hash << 4) + (*str);
		if ((x = hash & 0xF0000000L) != 0) {
			hash ^= (x >> 24);
		}
		hash &= ~x;
	}
	return hash;
}

static void hash_freenode(HashNode * node)
{
	if (node == NULL)
		return;

	if (node->next != NULL)
		hash_freenode(node->next);

	free(node);
}

void hash_init(HashNode * table[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
		table[i] = NULL;
}

void hash_freetable(HashNode * table[], int size)
{
	int i;
	for (i = 0; i < size; ++i) {
		hash_freenode(table[i]);
		table[i] = NULL;
	}
}

HashNode *hash_insert(HashNode * table[], int size, int hashvalue, int data)
{
	int index;
	HashNode *tmp;

	if ((tmp = hash_lookup(table, size, hashvalue)) != NULL)
		return tmp;

	index = hashvalue % size;
	tmp = table[index];

	if (tmp == NULL) {
		table[index] = malloc(sizeof(HashNode));
		table[index]->hash = hashvalue;
		table[index]->data = data;
		table[index]->next = NULL;

		return table[index];
	}

	while (tmp->next != NULL)
		tmp = tmp->next;

	if ((tmp->next = malloc(sizeof(HashNode))) == NULL)
		return NULL;
	tmp->next->hash = hashvalue;
	tmp->next->data = data;
	tmp->next->next = NULL;

	return tmp->next;
}

HashNode *hash_lookup(HashNode * table[], int size, int hashvalue)
{
	int index;
	HashNode *tmp;

	index = hashvalue % size;
	tmp = table[index];

	if (tmp == NULL) {
		return NULL;
	}

	if (tmp->hash == hashvalue)
		return tmp;

	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->hash == hashvalue)
			return tmp;
	}

	return NULL;		/* not found */
}
