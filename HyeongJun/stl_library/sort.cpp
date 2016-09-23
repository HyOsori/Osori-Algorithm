#include <algorithm>
#include <time.h>
#include "../head/nanosecond2second.h"
using namespace std;

FILE* fi;

int main(int argc,char* argv[]){
	struct timespec start,end;

	if(argv[1]==NULL){
		printf("e.g>./<execute file name> <input.txt>\n");
		return 0;
	}
	fi = fopen(argv[1],"r");
	int array[1000000];
	int key;
	int i=0;
	while(!feof(fi)){
		fscanf(fi,"%d",&key);
		array[i++]=key;
	}
	int length = i-1;
	clock_gettime(CLOCK_REALTIME,&start);
	sort(array,array+length);
	clock_gettime(CLOCK_REALTIME,&end);
	for(i=0;i<length;i++){
		printf("%d ",array[i]);
	}
	printf("\n");

//	unsigned int total=end.tv_sec-start.tv_sec;
//	unsigned int nano_time=end.tv_nsec-start.tv_nsec;
//	printf("second:%u\n",total);
//	printf("nano second:%u\n",nano_time);
	convert2second(&start,&end);
	return 0;
}
