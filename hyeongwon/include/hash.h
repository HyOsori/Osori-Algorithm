#ifndef HASH_H
#define HASH_H

#include <stdint.h>
#include "list.h"

struct hash_table {
	uint64_t        size;   /* size of hash table. */
	struct list**   bucket; /* array of bucket list. */
};

#endif
