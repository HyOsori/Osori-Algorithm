#include <stdio.h>
#include "counting_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "insertion_sort.h"

FILE* fi;

int main(int argc, char* argv[]){
	if(argv[1]==NULL || argv[2]==NULL){
		printf("ERROR : Insert the arguments\ne.g)sorting_exe Q sample.txt\n");
		return 0;
	}

	fi = fopen(argv[2],"r");

	int arr[100000];
	int* tarr;
	int num;
	int i=0;
	char sort_type;

	sort_type = *argv[1];

	while(!feof(fi)){
		fscanf(fi,"%d ",&num);
		arr[i++]=num;
	}
	int length = i;
	int tlength;
	switch(sort_type){
		case 'Q':
			quick_sort(arr,0,length-1);
			break;
		case 'M':
			tarr=(int*)malloc(sizeof(int)*length);
			for(i=0;i<length;i++){
				tarr[i]=arr[i];
			}
			merge_sort(arr,tarr,0,length-1);
			break;
		case 'C':
			tlength = maximum(arr,length)+1;
			tarr = (int*)malloc(sizeof(int)*tlength);
			counting_sort(arr,tarr,length,tlength);
			break;
		case 'I':
			insert_sort(arr,length);
			break;
		default:
			printf("ERROR : Input appropriate arguments\nyou should input Q,M,I and C\n");
			return 0;
			break;
	}
	print_arr(arr,length);

	return 0;
}

