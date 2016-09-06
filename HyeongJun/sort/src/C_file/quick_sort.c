#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//I select the pivot randomly, and then swap it and the start element of array
//Is it okay?

FILE* fi;
void quick_sort(int arr[], int p, int r);
int partition(int arr[], int p, int r);
void swap(int* a, int* b);
void print_arr(int arr[], int length);
int main(int argc,char* argv[]) {
	int arr[100000];
	int i = 0;
	fi = fopen(argv[1], "r");
	while (!feof(fi)) {
		fscanf(fi, "%d ", &arr[i++]);

	}
	//int arr[] = { 6,10,13,5,8,3,2,11 };
	int length = i;
	print_arr(arr, length);
	quick_sort(arr, 0, length - 1);
	print_arr(arr, length);
}

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
	for (i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
