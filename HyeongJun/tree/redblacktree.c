#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0
FILE* fi;

typedef int element_type;
struct node;
typedef struct node* position;
typedef struct node* tree;
struct node {
	element_type element;
	int key;
	position left;
	position right;
	position parent;
	int color;
};

position singleRotateLeft(position p);
position singleRotateRight(position p);
position doubleRotateLeft(position p);
position doubleRotateRight(position p);
position insertLeftCase(position p);
position insertRightCase(position p);
tree insert(tree t, int x);
position findMaxWithLeft(tree t);
position findMinWithRight(tree t);
position deletionCaseLeft(position p);
position deletionCaseRight(position p);
tree deletion(tree t, int x);
void printInorder(tree t);

int main(int argc, char* argv[]) {
	fi = fopen(argv[1], "r");
	tree t = NULL;
	int key;
	while (!feof(fi)) {
		fscanf(fi, "%d ", &key);
		t = insert(t, key);
	}
	return BLACK;

}
position singleRotateLeft(position p) {
	position tmp = p->left;
	p->left = tmp->right;
	tmp->right = p;
	tmp->parent = p->parent;
	p->parent = tmp;
	return tmp;
}
position singleRotateRight(position p) {
	position tmp = p->right;
	p->right = tmp->left;
	tmp->left = p;
	tmp->parent = p->parent;
	p->parent = tmp;
	return tmp;
}
position doubleRotateLeft(position p) {
	p->left = singleRotateRight(p->left);
	return singleRotateLeft(p);
}
position doubleRotateRight(position p) {
	p->right = singleRotateLeft(p->right);
	return singleRotateRight(p);
}
tree insert(tree t, int x) {
	if (t == NULL) {
		t = (tree)malloc(sizeof(struct node));
		t->key = x;
		t->color = BLACK;
		t->left = t->right = (position)malloc(sizeof(struct node));
		t->left->key = t->right->key = BLACK;
		t->left->color = t->right->color = BLACK;
		t->parent = NULL;
		t->left->parent = t->right->parent = t;
	}
	else if (t->key == BLACK) {
		position tmp = (position)malloc(sizeof(struct node));
		tmp->key = x;
		tmp->color = RED;
		tmp->left = tmp->right = t;
		return tmp;
	}
	else {
		if (x < t->key) {
			t->left = insert(t->left, x);
			t->left->parent = t;
			t = insertLeftCase(t);
		}
		else  if (x>t->key) {
			t->right = insert(t->right, x);
			t->right->parent = t;
			t = insertRightCase(t);
		}
		else {
			printf("this key alreay exists\n");
		}
	}

	return t;
}
position insertLeftCase(position p) {
	if (p->color == BLACK) {
		if (p->left->color == RED && p->right->color == RED) {
			if (p->left->left->color == RED || p->left->right->color == RED) {//LLr LRr
				p->color = RED;
				p->left->color = p->right->color = BLACK;
			}
		}
		else if (p->left->color == RED && p->right->color == BLACK) {
			if (p->left->left->color == RED) {//LLb
				p = singleRotateLeft(p);
				p->color = BLACK;
				p->right->color = RED;
			}
			else if (p->left->right->color == RED) {//LRb
				p = doubleRotateLeft(p);
				p->color = BLACK;
				p->right->color = RED;
			}
		}
	}
	return p;
}
position insertRightCase(position p) {
	if (p->color == BLACK) {
		if (p->left->color == RED && p->right->color == RED) {
			if (p->right->right->color == RED || p->right->left->color == RED) {//RRr RLr
				p->color = RED;
				p->right->color = p->left->color = BLACK;
			}
		}
		else if (p->right->color == RED && p->left->color == BLACK) {
			if (p->right->right->color == RED) {//RRb
				p = singleRotateRight(p);
				p->color = BLACK;
				p->left->color = RED;
			}
			else if (p->right->left->color == RED) {//RLb
				p = doubleRotateRight(p);
				p->color = BLACK;
				p->left->color = RED;
			}
		}
	}
	if (p->parent == NULL) {
		p->color = BLACK;
	}
	return p;
}
void printInorder(tree t) {
	if (t->key != BLACK) {
		printInorder(t->left);
		printf("%d", t->key);
		if (t->color == RED) {
			printf("(r) ");
		}
		else {
			printf("(b) ");
		}
		printInorder(t->right);
	}
}
position findMaxWithLeft(tree t) {
	t = t->left;
	while (t->right->key != BLACK) {
		t = t->right;
	}
	return t;
}
position findMinWithRight(tree t) {
	t = t->right;
	while (t->left->key != BLACK) {
		t = t->left;
	}
	return t;
}

tree deletion(tree t, int x) {
	if (t == NULL) {
		printf("Tree is empty\n");
	}
	else if (t->key == BLACK) {
		printf("%d is not existed in the tree\n", x);
	}
	else if (x < t->key) {
		t->left = deletion(t->left, x);
	}
	else if (x > t->key) {
		t->right = deletion(t->right, x);
	}
	else if (t->left->key != BLACK && t->right->key != BLACK) {
		//In case that left child is existed
		position replace = findMaxWithLeft(t);
		t->key = replace->key;
		t->left = deletion(t->left, replace->key);
	}
	else if (t->left->key != BLACK) {
		position replace = findMaxWithLeft(t);
		t->key = replace->key;
		t->left = deletion(t->left, replace->key);
	}
	else if (t->right->key != BLACK) {
		position replace = findMinWithRight(t);
		t->key = replace->key;
		t->right = deletion(t->right, replace->key);
	}
	else {// (t->left->key ==BLACK && t->right->key == BLACK )
		if (t->color == RED) {
			t = t->left;
		}
		else {
			t->key = BLACK;
			t->color = 2;
		}
	}
	if (t->key != BLACK) {
		if (t->left->color == 2) {
			t = deletionCaseLeft(t);
		}
		else if (t->right->color == 2) {
			t = deletionCaseRight(t);
		}
	}
	return t;
}
position deletionCaseLeft(position p) {
	if (p->right->color == BLACK && p->right->left->color == BLACK && p->right->right->color == BLACK) {
		//In case that black sibling with black children
		if (p->color == BLACK) {
			//In case that the parent node is black
			p->left->color = BLACK;
			p->color = 2;
			p->right->color = RED;
		}
		else if (p->color == RED) {
			//In case that the parent node is color
			p->left->color = BLACK;
			p->color = BLACK;
			p->right->color = RED;
		}
	}
	else if (p->right->color == BLACK) {
		//In case that the black sibling with a child
		if (p->right->left->color == RED) {
			//In case that the left child is color
			p = doubleRotateRight(p);
			p->color = p->left->color;
			p->left->color = BLACK;
			p->left->left->color = BLACK;
		}
		else if (p->right->right->color == RED) {
			//In case that  the right child is color
			p = singleRotateRight(p);
			p->color = p->left->color;
			p->left->color = BLACK;
			p->right->color = BLACK;
			p->left->left->color = BLACK;
		}
	}
	else if (p->right->color == RED) {
		//In case that the color sibling is existed
		p = singleRotateRight(p);
		p->color = BLACK;
		p->left->color = BLACK;
		p->left->left->color = BLACK;
		p->left->right->color = RED;
		p->right->color = BLACK;
	}

	return p;
}
position deletionCaseRight(position p) {
	if (p->left->color == BLACK && p->left->left->color == BLACK && p->left->right->color == BLACK) {
		//In case that black sibling with black children
		if (p->color == BLACK) {
			//In case that the parent node is black
			p->right->color = BLACK;
			p->color = 2;
			p->left->color = RED;
		}
		else if (p->color == RED) {
			//In case that the parent node is color
			p->right->color = BLACK;
			p->color = BLACK;
			p->left->color = RED;
		}
	}
	else if (p->left->color == BLACK) {
		//In case that the black sibling with a child
		if (p->left->left->color == RED) {
			//In case that the left child is color
			p = doubleRotateLeft(p);
			p->color = p->right->color;
			p->right->color = BLACK;
			p->right->right->color = BLACK;
		}
		else if (p->left->right->color == RED) {
			//In case that  the right child is color
			p = singleRotateLeft(p);
			p->color = p->right->color;
			p->right->color = BLACK;
			p->left->color = BLACK;
			p->right->right->color = BLACK;
		}
	}
	else if (p->right->color == RED) {
		//In case that the color sibling is existed
		p = singleRotateLeft(p);
		p->color = BLACK;
		p->right->color = BLACK;
		p->right->right->color = BLACK;
		p->right->left->color = RED;
		p->left->color = BLACK;
	}

	return p;
}
