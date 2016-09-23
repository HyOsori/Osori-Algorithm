#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

FILE* fi;

void merge_sort(int arr[],int tarr[],int start, int end);
void merge(int arr[], int tarr[], int start, int end);
void swap(int* a, int* b);
void print_arr(int arr[], int length);

int main(int argc, char* argv[]) {
	int arr[100000];
	int i = 0;
	fi = fopen(argv[1], "r");
	while (!feof(fi)) {
		fscanf(fi, "%d ", &arr[i++]);

	}
	//int arr[] = { 5,6,1,3,7,9, };
	int length = i;
	int* tarr = (int*)malloc(sizeof(int)*length);
	for (i = 0; i < length; i++) {
		tarr[i] = arr[i];
	}
	printf("Merge Sort\n");
	merge_sort(arr,tarr, 0, length-1);
	print_arr(arr, length);

	return 0;
}
void merge_sort(int arr[], int tarr[], int start, int end) {
	if (start < end) {
		int ret;
	 	ret = fork();
		int status=0;
		int center = (start + end) / 2;
		if(ret<0){
			printf("ERROR\n");
		}
		if(ret>0){
			merge_sort(arr,tarr,start,center);
		}
		else{	
			merge_sort(arr,tarr,center+1,end);
			wait(&status);
			merge(arr, tarr, start, end);
		}
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

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void print_arr(int arr[], int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

