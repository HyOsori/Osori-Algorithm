/*
	Reference : https://gist.github.com/zhpengg/2873424
	Thanks for reference
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX_LEVEL 10

typedef struct node{
	int key;
	struct node **forward;
}node;
/*
	forward : used for skipping keys
	key : index of list
*/

typedef struct skiplist{
	int level;
	struct node *header;
}skiplist;
/*
	level : level of skip list. Determined randomly.
	header : roughly same as in list's header. Just think about linked list.
*/

void init(skiplist *list);
int level_determine();
void insertion(skiplist *list, int key);
void search(skiplist *list, int key);

int main() {
	int i,play=1;
	skiplist * list;

	list = (skiplist *)malloc(sizeof(skiplist));
	skiplist_init(list);

	srand(time(NULL));

	for(i=0;i<100;i++)
		insertion(list,rand()%100+1);

	do{
		printf("Skip list : 1.insertion 2.serach 3.deletion\n");

		scanf("%d", &play);
	}while(play!=0);

	return 0;
}

void init(skiplist *list){
	int i;

	node *header = (node*)malloc(sizeof(node));
	list->header = header;
	header->key = INT_MAX;

	header->forward = (node**)malloc(sizeof(node*)*(MAX_LEVEL + 1));

	for(i = 0;i<=MAX_LEVEL;i++)
        header->forward[i] = list->header;

	list->level = 1;
}
int level_determine(){
	int level = 1;
	
	srand(time(NULL));
	//Initializing random seed

	while (rand()%2==0 && level<MAX_LEVEL)
		level++;
	//Coin toss & prevent to overflow

	return level;
}
void insertion(skiplist *list, int key){
	node *update[MAX_LEVEL + 1];
	node *new = list->header;
	node *tmp;
	int i,level;

	for(i=list->level;i>=1;i--) {
        	while(new->forward[i]->key < key)
			new = new->forward[i];
		//Find where to insert at "same level"

		update[i] = new;
		//save the information(level)
	}
	//Find where to insert by subtracting level

	new = new->forward[1];
	//Move forward once to insert new key(level 1)

	if(key==new->key)
		return;
	//When key is existing already

	else{
		level = level_determine();
		//Determine new key's level

		if(level>list->level){
			for(i=list->level+1;i<=level;i++)
				update[i] = list->header;
			//New level's occur : initializing(Pointing header). Same as function init().

			list->level = level;
			//level resetting
		}
		//When higher level occurs

		new = (node*)malloc(sizeof(node));
		//Allocating new memory

		new->key = key;
		mew->forward = (node**)malloc(sizeof(node*)*(level+1));
		//Setting new key's information

		for(i=1;i<=level;i++){
			new->forward[i] = update[i]->forward[i];
			//Saving information of new key's level(look above)
			update[i]->forward[i] = new;
		}
	}
}
void search(skiplist *list, int key){
	node *index = list->header;
	//Search begins at the header
	int i;

	for(i=list->level;i>=1;i--){
		while(index->forward[i]->key<key)
			index = index->forward[i];
		//searching at same level
	}
	//searching by subtracting level

	if(x->forward[1]->key==key) {
		printf("*************\n");
		printf("Key %d found!\n", key);
		printf("*************\n");	
	}
	else{
		printf("**************\n");
		printf("Can't find %d!\n", key);
		printf("**************\n");
	}
}
void skiplist_node_free(snode *x) {
    if (x) {
        free(x->forward);
        free(x);
    }
}
int delete(skiplist *list, int key){
    int i;
    snode *update[SKIPLIST_MAX_LEVEL + 1];
    snode *x = list->header;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }

    x = x->forward[1];
    if (x->key == key) {
        for (i = 1; i <= list->level; i++) {
            if (update[i]->forward[i] != x)
                break;
            update[i]->forward[i] = x->forward[i];
        }
        skiplist_node_free(x);

        while (list->level > 1 && list->header->forward[list->level]
                == list->header)
            list->level--;
        return 0;
    }
    return 1;
}

void skiplist_free(skiplist *list)
{
    snode *current_node = list->header->forward[1];
    while(current_node != list->header) {
        snode *next_node = current_node->forward[1];
        free(current_node->forward);
        free(current_node);
        current_node = next_node;
    }
    free(current_node->forward);
    free(current_node);
    free(list);
}

void skiplist_dump(skiplist *list) {
    snode *x = list->header;
    while (x && x->forward[1] != list->header) {
        printf("%d[%d]->", x->forward[1]->key, x->forward[1]->value);
        x = x->forward[1];
    }
    printf("NIL\n");
}
