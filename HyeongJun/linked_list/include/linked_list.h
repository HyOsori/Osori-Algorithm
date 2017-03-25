#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
struct node;
typedef struct node* position;
typedef position list;

struct node{
	int key;
	position prev;
	position next;
};

void insert(list l,int key);
void deletion(list l,int key);
position find(list l,int key);
position find_previous(list l,int key);
list create_list(list l);
void print_list(list l);

#endif
