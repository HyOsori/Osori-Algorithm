#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

/*	I skipped counting sort, cause these arrays have no duplicated numbers.
	counting sort is only useful in arrays that have duplicated numbers.
*/
void init(int *arr, int size);
void insertion_sort(int *arr, int size);
void merge_sort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);
void selection_sort(int *arr, int size);
void quick_sort(int *arr, int left, int right);
int partition(int *arr, int left, int right);

int main(){
	int small[10000];
	int medium[50000];
	int large[100000];
	int play = 1, num;
	clock_t start, end;

	do{
		printf("1 : insertion sort / 2 : merge sort / 3 : selection sort / 4 : quick sort\n");

		init(small, 10000);
		init(medium, 50000);
		init(large, 100000);
		//initializing arrys
		
		scanf("%d", &num);

		switch(num){
			case 1:
				insertion_sort(small,10000);
				insertion_sort(medium,50000);
				insertion_sort(large,100000);
				//insertion sort
				break;

			case 2:
				start = clock();
				merge_sort(small,0,10000-1);
				end = clock();
				printf("Sorting time : %lf\n", (double)(end - start)/1000);

				start = clock();
				merge_sort(medium,0,50000-1);
				end = clock();
				printf("Sorting time : %lf\n", (double)(end - start)/1000);

				start = clock();
				merge_sort(large,0,100000-1);
				end = clock();
				printf("Sorting time : %lf\n", (double)(end - start)/1000);
				//merge sort
				break;

			case 3:
				selection_sort(small,10000);
				selection_sort(medium,50000);
				selection_sort(large,100000);
				//selection sort
				break;

			case 4:
				start = clock();
				quick_sort(small,0,10000-1);
				end = clock();
				printf("Sorting time : %lf\n", (double)(end - start)/1000);

				start = clock();
				quick_sort(medium,0,50000-1);
				end = clock();
				printf("Sorting time : %lf\n", (double)(end - start)/1000);

				start = clock();
				quick_sort(large,0,100000-1);
				end = clock();
				printf("Sorting time : %lf\n", (double)(end - start)/1000);
				//quick sort
				break;

			default:
				printf("Error! please press right number\n");
				//error case
				continue;
		}
		printf("If you want to quit, please enter 0. Or press any number!\n");
		scanf("%d", &play);
	}while(play!=0);	


	return 0;
}
void init(int *arr, int size){
	int i,tmp,rand_num;

	srand(time(NULL));
	//Setting random seed

	for(i=0;i<size;i++)
		arr[i] = i+1;
	//Setting array

	for(i=0;i<size;i++){
		rand_num = rand()%size;
		//Setting random number

		tmp = arr[rand_num];
		arr[rand_num] = arr[i];
		arr[i] = tmp;  
	}	 
	//mixing array

}
void insertion_sort(int *arr, int size){
	int i,j,tmp;
	clock_t start, end;
	
	start = clock();

	for(i=0;i<size;i++){
		for(j=0;j<i;j++){
			if(arr[i]<=arr[j])
				break;
		}
		//finding insertion point
		if(i!=j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}	

	end = clock();

	printf("Sorting time : %lf\n", (double)(end - start)/1000);
}
void merge_sort(int *arr, int left, int right){
	int mid;

	if(left<right){
		mid = (left+right)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);	
	}
}
void merge(int *arr, int left, int mid, int right){
	int left_first = left;
	int right_first = mid + 1;
	int index = left;
	int i;
	int sorted[MAX];

	while(left_first<=mid && right_first<=right){
		if(arr[left_first]<=arr[right_first])
			sorted[index++] = arr[left_first++];
		else
			sorted[index++] = arr[right_first++];
	}
	if(left_first<=mid){
		for(i=left_first;i<=mid;i++)
			sorted[index++] = arr[i];
	}
	else{
		for(i=right_first;i<=right;i++)
			sorted[index++] = arr[i];
	}
	for(i=left;i<=right;i++)
		arr[i] = sorted[i];
	//merging
}
void selection_sort(int *arr, int size){
	int i,j,tmp,least;
	clock_t start, end;

	start = clock();

	for(i=0;i<size;i++){
		least = i;

		for(j=i;j<size;j++){
			if(arr[least]>arr[j])
				least = j;
		}

		tmp = arr[least];
		arr[least] = arr[i];
		arr[i] = tmp;
	}
	//find least number then swap it.

	end = clock();

	printf("Sorting time : %lf\n", (double)(end - start)/1000);	
}
int partition(int *arr, int left, int right){
	int pivot,tmp;
	int low,high;

	low = left;
	high = right + 1;
	pivot = arr[left];

	do{
		do{
			low++;
		}while(low<=right && arr[low]<pivot);

		do{
			high--;
		}while(high>=left && arr[high] > pivot);
	
		if(low<high){
			tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
	}while(low<high);
		
	tmp = arr[left];
	arr[left] = arr[high];
	arr[high] = tmp;
	//select pivot and sorting

	return high;
}
void quick_sort(int *arr, int left, int right){
	int q;

	if(left<right){
		q = partition(arr,left,right);
		quick_sort(arr,left,q-1);
		quick_sort(arr,q+1,right);
	}
}

