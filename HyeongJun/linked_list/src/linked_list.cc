#include "linked_list.h"

list create_list(list l){
	l = (list)malloc(sizeof(struct node));
	l->key=100000;
	l->next=NULL;
	l->prev=NULL;

	return l;
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
		cout << "the key "<< tmp->key << " is inserted"<<endl;
	}
	else{
		cout << "the key " << key << " already exists"<<endl;
	}

}
	
void deletion(list l,int key){
	position tmp = find(l,key);
	position prev;
	position next;
	if(tmp==NULL){
		cout << "the key " << key << " does not exist" << endl;
	}
	else{
		prev=find_previous(l,key);
		next=tmp->next;
		free(tmp);
		prev->next=next;
		if(next!=NULL){
			next->prev=prev;
		}
		cout << "the key " << key << " is deleted" <<endl;
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
	if(tmp==NULL){
		cout << "The list is empty" << endl;
		return ;
	}
	while(tmp!=NULL){
		cout << "(" << tmp->key << ") ";
		tmp=tmp->next;
	}
	cout << endl;
}
