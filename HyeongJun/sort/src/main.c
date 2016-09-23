#include <stdio.h>
#include "counting_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "insertion_sort.h"
#include "nanosecond2second.h"
#include <time.h>

FILE* fi;

int main(int argc, char* argv[]){
	if(argv[1]==NULL || argv[2]==NULL){
		printf("ERROR : Insert the arguments\ne.g)sorting_exe Q sample.txt\n");
		return 0;
	}

	fi = fopen(argv[2],"r");

	int arr[1000000];
	int* tarr;
	int num;
	int i=0;
	char sort_type;
	struct timespec start,end;
	sort_type = *argv[1];

	while(!feof(fi)){
		fscanf(fi,"%d ",&num);
		arr[i++]=num;
	}
	int length = i;
	int tlength;
	switch(sort_type){
		case 'Q':
			clock_gettime(CLOCK_REALTIME,&start);	
			quick_sort(arr,0,length-1);
			clock_gettime(CLOCK_REALTIME,&end);
			break;
		case 'M':
			tarr=(int*)malloc(sizeof(int)*length);
			for(i=0;i<length;i++){
				tarr[i]=arr[i];
			}
			clock_gettime(CLOCK_REALTIME,&start);	
			merge_sort(arr,tarr,0,length-1);
			clock_gettime(CLOCK_REALTIME,&end);
			break;
		case 'C':
			tlength = maximum(arr,length)+1;
			tarr = (int*)malloc(sizeof(int)*tlength);
			clock_gettime(CLOCK_REALTIME,&start);	
			counting_sort(arr,tarr,length,tlength);
			clock_gettime(CLOCK_REALTIME,&end);
			break;
		case 'I':
			clock_gettime(CLOCK_REALTIME,&start);	
			insert_sort(arr,length);
			clock_gettime(CLOCK_REALTIME,&end);
			break;
		default:
			printf("ERROR : Input appropriate arguments\nyou should input Q,M,I and C\n");
			return 0;
			break;
	}
	print_arr(arr,length);
	
	printf("\n");
	convert2second(&start,&end);
	return 0;
}

