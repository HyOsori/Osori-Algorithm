#ifndef LIST_H
#define LIST_H

#include <stdint.h>

struct node
{
	struct node*    prev;
	struct node*    next;
    uint64_t        key;
    void*           data;
};

struct list
{
    struct node*    head;
    struct node*    tail;
    uint64_t        count;
};

struct list* create_list(void);
struct node* create_list_node(void*);
struct node* search_list_node(struct list*, uint64_t);
struct node* remove_list_node(struct list*, struct node*);
struct node* list_push_back(struct list*, void*);
struct node* list_push_front(struct list*, void*);
struct node* list_pop_back(struct list*);
struct node* list_pop_front(struct list*);


#endif
