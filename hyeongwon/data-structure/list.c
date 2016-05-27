#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;	// all node has unique key
	int data;	// node's satellite data
	struct node *prev;
	struct node *next;
} Node;

typedef struct list
{
	int count;
	Node *head;
} List;

Node* CreateNode(int key, int data)
{
	Node* new_node = (Node *)malloc(sizeof(Node));

	if(new_node != NULL)
	{
		new_node->key = key;
		new_node->data = data;
		return new_node;
	}
	else
	{
		printf("Memory Full\n");
		return NULL;
	}
}

void InitList(List* list)
{
	list->count	= 0;
	list->head = NULL;
}

void InsertListNode(List *list, Node *node)
{
	node->prev = NULL;

	if(list->head == NULL)
	{
		list->head = node;
		node->next = NULL;
	}
	else
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}

	list->count++;
}

Node* SearchListNode(List *list, int key)
{
	Node *ptr = list->head;
	while(ptr != NULL)
	{
		if(key == ptr->key)
			return ptr;
		ptr = ptr->next;
	}

	return NULL;
}

void DeleteListNode(Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

void PrintList(List *list)
{
	Node *ptr = list->head;
	
	while(ptr != NULL)
	{
		printf("[%d] <-> ", ptr->data);
		ptr = ptr->next;
	}
	printf("[end]\n");
}

int main(void)
{
	int i;
	List list;

	srand(time(NULL));
	
	InitList(&list);

	for(i=0; i<100; i++){
		Node *temp = CreateNode(i+1, rand()%100);
		InsertListNode(&list, temp);
	}

	PrintList(&list);

	Node *temp = SearchListNode(&list, 3);
	if(temp != NULL)
		DeleteListNode(temp);

	PrintList(&list);

	return 0;
}
