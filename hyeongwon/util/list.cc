#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
Create and initialize the list structure. 
@return created list structure. */
struct list*
create_list(void)
{
    struct list* list =
        (struct list*) malloc(sizeof(struct list));
    list->head = list->tail = nullptr;
    list->count = 0;

    return list;
}

/**
Create and initialize the list node. 
@return created list node. */
struct node*
create_list_node(
    void*           data)   /* !< in: data */
{
    struct node* node = 
        (struct node*)malloc(sizeof(struct node));
    if(node == nullptr) {
        perror("memory allocation error");
        return nullptr;

    }
    node->prev = node->next = nullptr;
    node->data = data;

    return node;
}

/**
Add data to the end of the list.
@return added list node. */
struct node*
list_push_back(
    struct list*        list,   /* !< in: list */
    void*               data)   /* !< in: data */
{
    struct node* node = create_list_node(data);

    if(list->head == nullptr) {
        /* Empty list. */
        list->head = node;
        list->tail = node;

    } else {
        /* Not empty list. */
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;

    }

    list->count++;

    return node;
}

/**
Add data to the start of the list.
@return added list node. */
struct node*
list_push_front(
    struct list*        list,   /* !< in: list */
    void*               data)   /* !< in: data */
{
    struct node* node = create_list_node(data);

    if(list->head == nullptr) {
        /* Empty list. */
        list->head = node;
        list->tail = node;

    } else {
        /* Not empty list. */
        node->next = list->head;
        list->head->prev = node;
        list->head = node;

    }

    list->count++;

    return node;
}

/**
Search list linearly and find out list node containing data.
@return list node if found or nullptr otherwise. */
struct node*
search_list_node(
    struct list*        list,   /* !< in: list */
    uint64_t            key)    /* !< in: key */
{
    struct node* node= list->head;
	
    while(!node) {
        /* Search from first to last list node. */
		if(node->key == key) {
			return node;

        }

		node = node->next;
	}

	return nullptr;
}

/**
Remove the first list node of the list and return it.
@return the first list node or nullptr if empty. */
struct node*
list_pop_front(
    struct list*        list)   /* !< in: list */
{
    struct node* node = list->head;

    if(node == nullptr) {
        /* Empty list. */
        return nullptr;

    } else {
        /* Not empty list. */
        return remove_list_node(list, node);

    }
}

/**
Remove the last list node of the list and return it.
@return the last list node or nullptr if empty. */
struct node*
list_pop_back(
    struct list*        list)   /* !< in: list */
{
    struct node* node = list->tail;

    if(node == nullptr) {
        /* Empty list. */
        return nullptr;

    } else {
        /* Not empty list. */
        return remove_list_node(list, node);

    }
}

/**
Remove list node from the list. 
@return removed list node. */
struct node*
remove_list_node(
    struct list*        list,   /* !< in: list */
    struct node*   node)  /* !< out: removed list node */
{
    if(node == list->head && node == list->tail) {
        /* One element in list. */
        list->head = list->tail = nullptr;

    } else if (node == list->head) {
        /* First element in list. */
        list->head = list->head->next;
        list->head->prev = nullptr;
        node->next = nullptr;

    } else if (node == list->tail) {
        /* Last element in list. */
        list->tail = list->tail->prev;
        list->tail->next = nullptr;
        node->prev = nullptr;

    } else {
        /* Otherwise */
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = node->next = nullptr;

    }

    list->count--;
    return node;
}
