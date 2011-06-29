#ifndef HASH_H
#define HASH_H

#define DATASIZE 3

typedef struct HashNodeTag {
	int hash;
	int data;
	struct HashNodeTag *next;
} HashNode;

unsigned int ELFHash(const char *str, unsigned int len);
void hash_freetable(HashNode * table[], int size);
HashNode *hash_insert(HashNode * table[], int size, int hashvalue, int data);
HashNode *hash_lookup(HashNode * table[], int size, int hashvalue);

#endif
