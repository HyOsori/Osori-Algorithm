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
void free_node(node *_node);
int deletion(skiplist *list, int key);
void free_list(skiplist *list);
void show(skiplist *list);

int main() {
	int i,play=1,num,insert_num,delete_num,search_num;
	skiplist list;

	init(&list);

	srand(time(NULL));

	for(i=0;i<100;i++)
		insertion(&list,rand()%100+1);

	do{
		printf("Skip list : 1.insertion 2.serach 3.deletion 4.show\n");
		scanf("%d", &num);
	
		switch(num){
			case 1:
				scanf("%d", &insert_num);
				insertion(&list,insert_num);

				break;
		
			case 2:
				scanf("%d", &search_num);
				search(&list,search_num);

				break;
	
			case 3:
				scanf("%d", &delete_num);
				deletion(&list,delete_num);

				break;

			case 4:
				show(&list);
							
				break;

			default:
				printf("Please press proper number!\n");
				continue;
		}
		printf("If you want to quit, please press 0. Or press any number!\n");
		scanf("%d", &play);
	}while(play!=0);
	
	free_list(&list);

	return 0;
}

void init(skiplist *list){
	int i;

	node *header = (node*)malloc(sizeof(node));
	list->header = header;
	header->key = INT_MAX;

	header->forward = (node**)malloc(sizeof(node*)*(MAX_LEVEL + 1));

	for(i=0;i<=MAX_LEVEL;i++)
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
		new->forward = (node**)malloc(sizeof(node*)*(level+1));
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
		//Searching at same level
	}
	//Searching by subtracting level

	if(index->forward[1]->key==key) {
		printf("*************\n");
		printf("Key %d found!\n", key);
		printf("*************\n");	
	}
	//When key is found

	else{
		printf("**************\n");
		printf("Can't find %d!\n", key);
		printf("**************\n");
	}
	//Oh, can't find key...
}
void free_node(node *_node){
	if(_node){
		free(_node->forward);
		//You should free forward first!(Prevent memory leak)

		free(_node);
	}
}
int deletion(skiplist *list, int key){
	int i;
	node *update[MAX_LEVEL + 1];
	node *del = list->header;

	for(i=list->level;i>=1;i--){
		while(del->forward[i]->key<key)
			del = del->forward[i];
		//Searching in same level

		update[i] = del;
		//Saving information before subtracting level
	}
	//Searching key to delete

	del = del->forward[1];
	//Move once forward

	if(del->key==key){
		for(i=1;i<=list->level;i++){
			if(update[i]->forward[i] != del) 
				break;
			update[i]->forward[i] = del->forward[i];
			//Connecting between deleted(Will be) node
		}
		free_node(del);
		//Delete node
	
		while(list->level>1 && list->header->forward[list->level]==list->header)
			list->level--;
		//Resetting skip list's level

		return 0;
	}
	//When find proper key

	return 1;
	//When can't find key to be deleted
}
void free_list(skiplist *list){
	node *current_node = list->header->forward[1];
   
	while(current_node!=list->header){
		node *next_node = current_node->forward[1];
		free(current_node->forward);
		//Must free forward first to prevent memory leak!

		free(current_node);
		current_node = next_node;
	}
	//Deleting all nodes while move forward
	free(current_node->forward);
	free(current_node);
	free(list);
}
void show(skiplist *list){
	node *index = list->header;
    
	while(index && index->forward[1]!=list->header){
		printf("%d->",index->forward[1]->key);
		index = index->forward[1];
	}
	//Showing all keys while move forward
	printf("Done!\n");
}
