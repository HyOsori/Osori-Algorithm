#ifndef __INSERTION_SORT_H_
#define __INSERTION_SORT_H_
#include <stdio.h>
#include <stdlib.h>
#define limit 1000
#include "swap.h"


//void copy_arr(int arr[], int tarr[], int start, int end)
void insert_sort(int arr[], int length);
void insert_sort(int arr[], int length) {
	int i, j, tmp;
	for (i = 1; i < length; i++) {
		for (j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
			else {
				break;
			}
		}
	}
}
#endif
