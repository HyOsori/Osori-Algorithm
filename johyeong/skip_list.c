#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_LEVEL 10

typedef struct _skip_list_node{
	struct _skip_list **forward;
	int key;
	int val;
}skip_list_node;

typedef struct _skip_list{
	skip_list_node *header;
	int level;
	int size;
}skip_list;

void init(skip_list *list);
void search(skip_list *list, int key);
void insertion(skip_list *list, int key, int value);
void deletion(skip_list *list);
int level_determination();

int main(){
	skip_list list;

	init(&list);
			

	return 0;
}

void init(skip_list *list){
	int i;
	skip_list_node *first_header;

	list->header = fist_header;
	first_header = (skip_list_node*)malloc(sizeof(skip_list_node));
	first_header -> key = INT_MAX;
	first_header -> forward = (skip_list_node**)malloc(sizeof(skip_list_node*)*(MAX_LEVEL + 1));

	for(i=0;i<=MAX_LEVEL;i++)
		first_heder[i] -> header = list_header;

	list->level = 1;
	list->size = 0;
}
void search(skip_list *list, int key){
	

}
void insertion(skip_list *list, int key, int value){
	

}
void deletion(skip_list *list);
int level_determination(){
	int level = 1;

	srand(time(NULL));

	while(rand()%2==0 && level < MAX_LEVEL)
		level++:

	return level;
}
