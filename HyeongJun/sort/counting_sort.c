#include <stdio.h>
#include <stdlib.h>

FILE* fi;

int maximum(int arr[], int length);
void counting_sort(int arr[], int tarr[], int length, int tlength);
void print_arr(int arr[], int length);
int main(int argc, char* argv[]) {
	int arr[100000];
	int i = 0;
	fi = fopen(argv[1], "r");
	while (!feof(fi)) {
		fscanf(fi, "%d ", &arr[i++]);

	}
	//int arr[] = { 4,1,3,4,3 };
	int length = i;
	int* tarr;
	//int min = minimum(arr, length);
	int tlength = maximum(arr, length)+1;
	tarr = (int*)malloc(sizeof(int)*tlength);
	
	print_arr(arr, length);
	counting_sort(arr, tarr, length, tlength);
	print_arr(arr, length);

	return 0;
}
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
void print_arr(int arr[], int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}