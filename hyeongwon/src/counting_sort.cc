#include <stdlib.h>

int FindLargest(int *, int);
void CountingSort(int *, int);

int FindLargest(
    int *arr,
    int n)
{
	int i;
	int largest = 0;
	
	for(i = 0; i < n; i++)
	{
		if(largest < arr[i])
			largest = arr[i];
	}
	
	return largest;
}

void CountingSort(
    int *arr,
    int n)
{
	int i, j, k;

	k = FindLargest(arr, n);

	int *temp = (int *)malloc(sizeof(int)*n);
	int *count = (int *)malloc(sizeof(int)*(k+1));
	
	for (i = 0; i <= k; i++) {
		count[i] = 0;
    }
	for (j = 0; j < n; j++) {
		count[arr[j]] = count[arr[j]] + 1;
    }
	for (i = 1; i <= k; i++) {
		count[i] = count[i] + count[i-1];
    }
	for (j = n-1; j >= 0; j--) {
		temp[count[arr[j]]] = arr[j];
		count[arr[j]] = count[arr[j]] - 1;
	}

	for(i = 0; i < n; i++) {
		arr[i] = temp[i];
    }
	
	free(temp);
	free(count);
}
