#ifndef __SWAP_H_
#define __SWAP_H_

#include<stdio.h>
#include<time.h>
void convert2second(struct timespec* start,struct timespec* end);

void convert2second(struct timespec* start,struct timespec* end){

	int i;
	int key;
	int unit = 100000000;
	unsigned int total = end->tv_sec-start->tv_sec;
	unsigned int nano = end->tv_nsec-start->tv_nsec;
	printf("time : %u.",total);
	while(1){
		key = nano/unit;
		if(key!=0){
			printf("%u\n",nano);
			break;
		}
		else{
			printf("0");
			unit/=10;
		}
	}
}
#endif
