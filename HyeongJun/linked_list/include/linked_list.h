#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

list create_list(list l){
	l = (list)malloc(sizeof(struct node));
	l->key=100000;
	l->next=NULL;
	l->prev=NULL;
}

void insert(list l,int key){
	position tmp = find(l,key);
	if(tmp==NULL){
		tmp = (position)malloc(sizeof(struct node));
		tmp->next=l->next;
		if(tmp->next!=NULL){
			tmp->next->prev=tmp;
		}
		l->next=tmp;
		tmp->key=key;
		tmp->prev=l;
		printf("the key %d is inserted\n",tmp->key);
	}
	else{
		printf("the key %d already exists\n",key);
	}

}
	
void deletion(list l,int key){
	position tmp = find(l,key);
	position prev;
	position next;
	if(tmp==NULL){
		printf("the key %d does not exist\n",key);
	}
	else{
		prev=find_previous(l,key);
		next=tmp->next;
		free(tmp);
		prev->next=next;
		if(next!=NULL){
			next->prev=prev;
		}
		printf("the key %d is deleted\n",key);
	}
}
position find(list l,int key){
	position tmp = l->next;

	while(tmp!=NULL&&tmp->key != key){
		tmp=tmp->next;
	}
	return tmp;
}
position find_previous(position l,int key){
	position tmp = find(l,key);
	position tmp2=l;
	if(tmp==NULL){
		return NULL;
	}
	else{
		while(tmp2->next!=tmp){
			tmp2=tmp2->next;
		}
		return tmp2;
	}
}
void print_list(list l){
	position tmp = l->next;
	while(tmp!=NULL){
		printf("(%d) ",tmp->key);
		tmp=tmp->next;
	}
	printf("\n");
}
#endif
