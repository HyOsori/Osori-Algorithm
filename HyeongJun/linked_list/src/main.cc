#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
FILE* fi;

int main(void){
	
	cout << "MANUAL : I:INSERT\tD:DELETE\tF:FIND\tP:PRINT ALL KEYS\tT:TERMINATE\n" << "\t you should capitalize the alphabet" << endl;
	char key;
	int i_key;
	list l=NULL;
	l=create_list(l);
	do{	
		cout << "COMMAND : ";	
		cin>>key;

		switch(key){
			case 'I':case 'D':case 'F':
				cout << "INPUT THE KEY : ";
				cin >> i_key;				
				if(key=='I'){
					insert(l,i_key);
				}
				else if(key=='F'){
					if(find(l,i_key)==NULL){
						cout << "the key " << i_key <<
						 " does not exist in the list" << endl;}
					else{
						cout << "the key " << i_key <<
						 " exists in the list" << endl;}
				}
				else{
					deletion(l,i_key);
				}
				break;
			
			
			case 'P':
				print_list(l);
				break;
			case 'T':
				return 0;
				break;
			default:
	cout << "MANUAL : I:INSERT\tD:DELETE\tF:FIND\tP:PRINT ALL KEYS\tT:TERMINATE\n" << "\t you should capitalize the alphabet" << endl;
				break;
		}

	}while(key!='E');
	return 0;
}
