#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "swap.h"

//I select the pivot randomly, and then swap it and the start element of array
//Is it okay?

FILE* fi;
void quick_sort(int arr[], int p, int r);
int partition(int arr[], int p, int r);
void print_arr(int arr[], int length);
void quick_sort(int arr[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(arr, p, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q + 1, r);
	}
}
int partition(int arr[], int p, int r) {
	srand(time(NULL));
	int pivot = -1;
	int i = p;
	int j = i + 1;
	while (pivot < p) {
		pivot = rand() % (r + 1);
	}
	
	swap(&arr[p], &arr[pivot]);
	pivot = arr[i];
	while (j <= r) {
		if(pivot>arr[j]){
			swap(&arr[++i],&arr[j++]);
		}
		else{
			j++;
		}
	}
	swap(&arr[p], &arr[i]);
	

	return i;
}
void print_arr(int arr[], int length) {
	int i;
	int check = arr[0];
	for (i = 0; i < length; i++) {
		if(check>arr[i]){
			printf("ERROR : Sorting algorithms is not appropriate\n");
		}
		else{
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}
