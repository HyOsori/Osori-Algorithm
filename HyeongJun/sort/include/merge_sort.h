#ifndef __MERGE_SORT_H_
#define __MERGE_SORT_H_
#include <stdio.h>
#include <stdlib.h>
#include "swap.h"


void merge_sort(int arr[],int tarr[],int start, int end);
void merge(int arr[], int tarr[], int start, int end);

void merge_sort(int arr[], int tarr[], int start, int end) {
	if (start < end) {
		int center = (start + end) / 2;
		merge_sort(arr, tarr, start, center);
		merge_sort(arr, tarr, center + 1, end);
		merge(arr, tarr, start, end);
	}
}
void merge(int arr[], int tarr[], int start, int end) {
	int left, left_end, right, right_end;
	int i = start;
	left = start;
	left_end = (start + end) / 2;
	right = left_end+1;
	right_end = end;
	while (left <= left_end && right <= right_end) {
		if (arr[left] < arr[right]) {
			tarr[start] = arr[left];
			start++;
			left++;
		}
		else {
			tarr[start] = arr[right];
			right++;
			start++;
		}
	}
	while (left <= left_end) {
		tarr[start] = arr[left];
		start++;
		left++;
	}
	while (right <= right_end) {
		tarr[start] = arr[right];
		start++;
		right++;
	}
	for (i; i <= end; i++) {
		arr[i] = tarr[i];
	}
}

#endif
