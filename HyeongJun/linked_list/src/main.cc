#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

FILE* fi;

int main(void){
	
	printf("MANUAL: I : insert\tD : delete\t P : print all keys\tE : END\n\t\tyou should input the key when you choose I or D\n");
	
	
	char key;
	int i_key;
	list l=NULL;
	l=create_list(l);
	do{	
		printf("COMMAND : ");
	
		scanf("%c",&key);
	
		switch(key){
			case 'I':case 'D':
				printf("INPUT THE KEY : ");
				scanf("%d", &i_key);
				if(key=='I'){
					insert(l,i_key);
				}
				else{
					deletion(l,i_key);
				}
				break;
			case 'P':
				print_list(l);
				break;
			case 'E':
				return 0;
				break;
			default:
				printf("MANUAL: I : insert\tD : delete\t P : print all keys\tE : END\n\t\tyou should input the key when you choose I or D\n");
				break;
		}

	}while(key!='E');
	return 0;
}
