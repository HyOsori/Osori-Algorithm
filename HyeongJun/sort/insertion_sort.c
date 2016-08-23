#include <stdio.h>
#include <stdlib.h>
#define limit 1000

FILE* fi;

//void copy_arr(int arr[], int tarr[], int start, int end)
void insert_sort(int arr[], int length);
void print_arr(int arr[], int length);
void swap(int* a, int* b);
int main(int argc, char* argv[]) {
	int arr[100000];
	int i=0;
	fi = fopen(argv[1], "r");
	while (!feof(fi)) {
		fscanf(fi,"%d ", &arr[i++]);
		
	}
	//int arr[] = { 5,67,2,1,30};
	int length = i;
	print_arr(arr, length);
	insert_sort(arr, length);
	print_arr(arr, length);

	return 0;
}
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
void print_arr(int arr[], int length){
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