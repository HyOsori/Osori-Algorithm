#include <stdlib.h>
#include <stdint.h>
#include "list.h"
#include "hash.h"

#define W_COMP_BIT  7
#define ODD_INTEGER 0x11010001
#define R           3
#define POW_R       8

uint64_t
hash_func(
    struct hash_table* ht,
    uint64_t key)
{
	return key % (ht->size); // Division Method (h = k mod m)
}

struct hash_table*
create_hash_table(
   uint64_t size)
{
	struct hash_table* ht = 
        (struct hash_table*)malloc(sizeof(hash_table));
	ht->size = size;
	ht->bucket = (struct list**) malloc(sizeof(struct list*)*size);
	for(uint64_t i = 0; i < size; i++)
	{
		ht->bucket[i] = create_list();
	}

    return ht;
}

void
insert_hash_table(
    struct hash_table* ht,
    struct node* node)
{
	uint64_t hash_val = hash_func(ht, node->key);
	list_push_front(ht->bucket[hash_val], node);
}

struct node*
search_hash_table(
    struct hash_table* ht,
    uint64_t key)
{
	uint64_t hash_val = hash_func(ht, key);
	return search_list_node(ht->bucket[hash_val], key);
}

void
delete_hash_table(
    struct hash_table* ht,
    struct node* node)
{
	uint64_t hash_val = hash_func(ht, node->key);
	remove_list_node(ht->bucket[hash_val], node);
}
