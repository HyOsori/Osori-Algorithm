#include <stdio.h>
#include <stdlib.h>

typedef struct _skip_list_node{
	struct **_skip_list;
	int key;
	void *val;
	float p;
}skip_list_node;

typedef struct _skip_list{
	skip_list_node header;
	int level;
	int max_level;
}skip_list;

void intit();

int main(){
			

	return 0;
}

void init(){

}
