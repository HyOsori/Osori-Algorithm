#include <stdio.h>
#include <algorithm>
#include <time.h>

using namespace std;

FILE* fi;

int main(int argc,char* argv[]){
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);

	if(argv[1]==NULL){
		printf("e.g>./<execute file name> <input.txt>\n");
		return 0;
	}
	fi = fopen(argv[1],"r");
	int array[10000];
	int key;
	int i=0;
	while(!feof(fi)){
		fscanf(fi,"%d",&key);
		array[i++]=key;
	}
	int length = i-1;
	sort(array,array+length);
	for(i=0;i<length;i++){
		printf("%d ",array[i]);
	}
	printf("\n");

	clock_gettime(CLOCK_REALTIME,&end);
	int total=end.tv_sec-start.tv_sec;
	int nano_time=end.tv_nsec-start.tv_nsec;
	printf("%d",total);
	printf(".%d\n",nano_time);
	
	return 0;
}
