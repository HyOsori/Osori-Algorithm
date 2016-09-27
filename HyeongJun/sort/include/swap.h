#ifndef __SWAP_H_
#define __SWAP_H_

#include <stdio.h>

void swap(int* a,int* b);

void swap(int* a,int* b){

	int c = *a;
 	*a = *b;
	*b= c;
	
}
#endif
