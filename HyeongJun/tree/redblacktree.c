#include <stdio.h>
#define external_node -1
#define red 1
#define black 0
FILE* fi;

struct node;
typedef int element_type;
typedef struct node* tree;
typedef struct node* position;
struct node {
	element_type element;
	int color;
	//if the node is red, value of color is 1, otherwise when the node is black, it is 0;
	int key;
	int size;
	position left;
	position right;
	position parent;
};

position case1(position node);
position case2(position node);
position case3(position node);
position case1_2(position node);
position case2_2(position node);
position case3_2(position node);
position tree_insert(tree t, int key);
tree rb_insert(tree t, int key);
int main(int argc, char* argv[]) {

	fi = fopen(argv[1], "r");

	int key;
	tree t = NULL;

	while (!feof(fi)) {
		fscanf(fi, "%d ", &key);
		t = rb_insert(t, key);
	}

	return 0;
}

position case1(position node) {
	node->parent->color = black;
	node->parent->parent->color = red;
	node->parent->parent->right->color = black;
	return node->parent->parent;
}
position case2(position node) {
	position c = node->parent->parent;
	position a = node->parent;
	position b = node;
	a->right = b->left;
	b->left = a;
	c->left = b;
	a->parent = b;
	b->parent = c;
	a->right->parent = a;
	return  a;
}
position case3(position node) {
	position c = node->parent->parent;
	position a = node->parent;
	position b = node;
	position d = c->parent;
	if (c == d->left) {
		d->left = b;
	}
	else {
		d->right = b;
	}
	c->left = b->right;
	b->right = c;
	b->parent = d;
	c->parent = b;
	c->left->parent = c;
	return b;
}
position case1_2(position node) {

	node->parent->color = black;
	node->parent->parent->color = red;
	node->parent->parent->left->color = black;
	return node->parent->parent;
}
position case2_2(position node) {
	position c = node->parent->parent;
	position a = node->parent;
	position b = node;
	c->right = b;
	a->left = b->left;
	b->right = a;
	a->parent = b;
	b->parent = c;
	a->left->parent = a;
	return a;
}
position case3_2(position node){
	position c = node->parent->parent;
	position a = node->parent;
	position b = node;
	position d = c->parent;
	if (d != NULL) {
		if (c == d->left) {
			d->left = b;
		}
		else {
			d->right = b;
		}
	}
	c->right = b->left;
	b->right = a;
	b->parent = d;
	c->parent = b;
	c->right->parent = c;
	return b;
}
position tree_insert(tree t, int key) {
	if (t == NULL) {
		t = (tree)malloc(sizeof(struct node));
		t->left = (position)malloc(sizeof(struct node));
		t->right = (position)malloc(sizeof(struct node));
		t->left->key = t->right->key = external_node;
		t->left->color = t->right->color = black;
		t->left->parent = t->right->parent = t;
		t->size = 1;
		t->key = key;
		t->color = black;
		t->parent = NULL;
	}
	else {
		while (t->key != external_node) {
			if (t->key > key) {
				t = t->left;
			}
			else if (t->key < key) {
				t = t->right;
			}
			else {
				printf("the key %d already existed\n", key);
				return NULL;

			}
		}
		t->key = key;
		t->left = (position)malloc(sizeof(struct node));
		t->right = (position)malloc(sizeof(struct node));
		t->left->key = t->right->key = external_node;
		t->left->color = t->right->color = black;
		t->left->parent = t->right->parent = t;
		t->size = 1;
	}
	return t;
}
tree rb_insert(tree t, int key) {
	
	if (t == NULL) {
		t = tree_insert(t, key);
		return t;
	}	
	
	position x = tree_insert(t, key);
	x->color = red;
	position y;

	
	while (x->parent != NULL&&x->parent->color == red) {
		if (x->parent == x->parent->parent->left) {
			y = x->parent->parent->right;
			if (y->color == red) {
				x = case1(x);
			}
			else if (x == x->parent->right) {
				x = case2(x);
				x = case3(x);
			}
			else {
				x = case3(x);
			}
		}
		else {
			if (x->parent == x->parent->parent->right) {
				y = x->parent->parent->left;
				if (y->color == red) {
					x = case1_2(x);
				}
				else if (x == x->parent->left) {
					x = case2_2(x);
					x = case3_2(x);
				}
				else {
					x = case3_2(x);
				}
			}
		}
	}
	t->color = black;
	return t;
}
