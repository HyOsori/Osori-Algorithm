#include <stdlib.h>

int MergeSort(int *, int);
void TopDownMergeSort(int *, int, int, int *);
void Merge(int *, int, int, int, int *);
void CopyArray(int *, int *, int, int);

int
MergeSort(
    int *arr,
    int size)
{
    int start = 0;
    int end = size;
    int* temp;
    
    temp = (int *)malloc(sizeof(int)*size);
    if (!temp) {
        return 0;
    }
    TopDownMergeSort(arr, start, end, temp);
    free(temp);

    return 1;
}

void
TopDownMergeSort(
    int *arr,
    int start,
    int end,
    int* temp)
{
    if(end - start < 2)
        return;

    int mid = (start + end)/2;
    TopDownMergeSort(arr, start, mid, temp);
    TopDownMergeSort(arr, mid, end, temp);
    Merge(arr, start, mid, end, temp);
    CopyArray(arr, temp, start, end);
}

void
Merge(
    int *arr,
    int start,
    int mid,
    int end,
    int* temp)
{
    int i = start;
    int j = mid;

    for (int k = start; k < end; k++) {
        if (i < mid && (j >= end || arr[i] <= arr[j])) {
            temp[k] = arr[i];
            i = i + 1;
        } else {
            temp[k] = arr[j];
            j = j + 1;
        }
    }

}

void
CopyArray(
    int* arr,
    int* temp,
    int start,
    int end)
{
    for (int i = start; i < end; i++) {
        arr[i] = temp[i];
    }
}



