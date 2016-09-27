#ifndef __COUNTING_SORT_H_
#define __COUNTING_SORT_H_
#include <stdio.h>
#include <stdlib.h>
#include "swap.h"


int maximum(int arr[], int length);
void counting_sort(int arr[], int tarr[], int length, int tlength);
int maximum(int arr[], int length) {
	int max = arr[0];
	int i;
	for (i = 0; i < length; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}
void counting_sort(int arr[], int tarr[], int length, int tlength) {
	int i;
	int* temp = (int*)malloc(sizeof(int)*length);
	for (i = 0; i < tlength; i++) {
		tarr[i] = 0;
	}
	for (i = 0; i < length; i++) {
		tarr[arr[i]]++;
	}
	for (i = 1; i < tlength; i++) {
		tarr[i] += tarr[i - 1];
	}
	for (i = length - 1; i >= 0; i--) {
		temp[tarr[arr[i]]-1] = arr[i];
		tarr[arr[i]]--;
	}
	for (i = 0; i < length; i++) {
		arr[i] = temp[i];
	}
}
#endif
