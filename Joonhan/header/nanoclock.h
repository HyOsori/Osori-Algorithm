#ifdef __CLOCK_H_   //to prevent double declaration of header
#define __CLOCK_H_

#include <stdio.h>
#include <time.h> 


void runtime(struct timespec* start, struct timespec* end);
void runtime(struct timespec* start, struct timespec* end){
    int key;
    int unit = 100000000; //to check the 'nano' by dividing
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
