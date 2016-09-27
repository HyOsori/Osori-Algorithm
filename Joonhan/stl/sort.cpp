#include <stdio.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include "timer2.h"

using namespace std;

FILE* fi;

int main(int argc,char *argv[])
{
    struct timespec start,end;

    if(argv[1]==NULL){
        printf("input file name\n");
        return 0;
    }

    fi = fopen(argv[1],"r");
    int array[100000];
    int key;
    int i = 0;
    while(!feof(fi)){
        fscanf(fi,"%d",&key);
        array[i++]=key;
    }
    int length = i-1;
    int way;
    printf("asend to 0 descend to 1\n");
    while(way==0||way==1){
    scanf("%d",&way);
    if(way==0||way==1){
        break;
    }
    else{
        printf("invalid value!!\n");
        return 0;
    }
    }

    current_utc_time(&start);
    if(way==0)
        sort(array,array+length);
    else
        sort(array,array+length,greater<int>());
    for (i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    current_utc_time(&end);
    printf("ns: %lu\n", end.tv_nsec-start.tv_nsec);
    return 0;
        
}

