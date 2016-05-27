#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

typedef struct hashTable {
	int size;
	List* bucket; //pointer of bucket array
} HashTable;

int HashFunc(HashTable* ht, int key)
{
	return key % (ht->size); // Division Method (h = k mod m)
}

void InitHashTable(HashTable* ht, int size)
{
	int i;

	ht->size = size;
	ht->bucket = (List *)malloc(sizeof(List)*size);
	for(i=0; i<size; i++)
	{
		InitList(&ht->bucket[i]);
	}
}

void InsertHashNode(HashTable* ht, Node* node)
{
	int hash_val = HashFunc(ht, node->key);
	InsertListNode(&ht->bucket[hash_val], node);
}

Node* SearchHashNode(HashTable* ht, int key)
{
	int hash_val = HashFunc(ht, key);
	return SearchListNode(&ht->bucket[hash_val], key);
}

void DeleteHashNode(HashTable* ht, Node* node)
{
	DeleteListNode(node);
}

void PrintHashTable(HashTable* ht)
{
	int i;
	int size = ht->size;

	for(i=0; i<size; i++)
	{
		printf("[%d] : ", i);
		PrintList(&ht->bucket[i]);
	}
}

int main(void)
{
	int i;
	srand(time(NULL));

	int size = 103;

	HashTable* ht = (HashTable *)malloc(sizeof(HashTable));
	InitHashTable(ht, size);

	printf("hellow\n");
	printf("%d\n", ht->size);

	for(i=0; i<size+50; i++)
	{
		Node* temp = CreateNode(i, rand()%100);
		InsertHashNode(ht, temp);
	}
	
	PrintHashTable(ht);
}

