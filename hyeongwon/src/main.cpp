//
//  main.cpp
//  [Algorithm]Sorting
//
//  Created by 장형원 on 2016. 4. 8..
//  Copyright © 2016년 jhw. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#define SWAP(X, Y) {int temp = X; X = Y; Y = temp;}

typedef enum {ERROR, INSERTION_SORT, MERGE_SORT, QUICK_SORT, COUNT_SORT} SORT_TYPE;

int SIZE = 1000000;

void usage()
{
    std::cerr << "Usage : <sort-type> <input-file> <output-file>" << std::endl;
}

bool CheckSorting(int *arr, int size)
{
    int i;

    for(i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            std::cerr << "Sorting Failure : ";
			printf("arr[%d] = %d -> arr[%d] = %d\n", i, arr[i], i+1, arr[i+1]);
            return false;
        }
    }

	std::cout << "Sort is Complete" << std::endl;

    return true;
}

void InsertionSort(int *arr, int size)
{
    int key, i, j;

    for(j = 1; j < size; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
}

void Merge(int *arr, int start, int mid, int end)
{
    int *temp = (int *)malloc(sizeof(int)*(end - start + 1));
    int i = start;
    int j = mid + 1;
    int k = 0;

    while(1)
    {
        if(arr[i] > arr[j])
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
        else
        {
            temp[k] = arr[i];
            k++;
            i++;
        }

        if(i > mid)
        {
            while(j <= end)
            {
                temp[k] = arr[j];
                k++;
                j++;
            }
            break;
        }

        if(j > end)
        {
            while(i <= mid)
            {
                temp[k] = arr[i];
                k++;
                i++;
            }
            break;
        }
    }

    for(i = start, k = 0; i <= end; i++, k++)
    {
        arr[i] = temp[k];
    }

    free(temp);
}

void MergeSort(int *arr, int start, int end)
{
    if(start >= end)
        return;

    int mid = (start + end)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, start, mid, end);

}

int Partition(int *arr, int p, int r)
{
    int pivot, temp;
    int i, j;

    pivot = arr[p];
    i = p;
    for(j = p+1; j <= r; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
            SWAP(arr[i], arr[j]);
        }
    }

    SWAP(arr[p], arr[i]);

    return i;
}

void QuickSort(int *arr, int p, int r)
{
    if(p < r)
    {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q-1);
        QuickSort(arr, q+1, r);
    }

}

int FindLargest(int *arr, int n)
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

void CountSort(int *arr, int n)
{
	int i, j, k;

	k = FindLargest(arr, n);

	int *temp = (int *)malloc(sizeof(int)*n);
	int *count = (int *)malloc(sizeof(int)*(k+1));
	
	for(i = 0; i <= k; i++)
		count[i] = 0;
	for(j = 0; j < n; j++)
		count[arr[j]] = count[arr[j]] + 1;
	for(i = 1; i <= k; i++)
		count[i] = count[i] + count[i-1];
	for(j = n-1; j >= 0; j--)
	{
		temp[count[arr[j]]] = arr[j];
		count[arr[j]] = count[arr[j]] - 1;
	}

	for(i = 0; i < n; i++)
		arr[i] = temp[i];
	
	free(temp);
	free(count);
}

SORT_TYPE GetSortType(const char * sname)
{
    if(strcmp(sname, "InsertionSort") == 0)
        return INSERTION_SORT;
    if(strcmp(sname, "MergeSort") == 0)
        return MERGE_SORT;
    if(strcmp(sname, "QuickSort") == 0)
        return QUICK_SORT;
	if(strcmp(sname, "CountSort") == 0)
		return COUNT_SORT;

    return ERROR;
}

int main(int argc, const char * argv[]) {
    
    if(argc != 4)
    {
        usage();
        exit(EXIT_FAILURE);
    }
    
    SORT_TYPE stype = GetSortType(argv[1]);
    if(stype == ERROR)
    {
        std::cerr << "Not Right Sorting" << std::endl;
        exit(EXIT_FAILURE);
    }

    FILE *ifp = fopen(argv[2], "r");
    if(ifp == NULL)
    {
        std::cerr << "Cannot open input file" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int i = 0;
    int arr[SIZE];

    while(!feof(ifp))
    {
        fscanf(ifp, "%u", &arr[i]);
        i++;
    }

	struct timer* timer = CreateTimer();
	
	CheckTime(&timer->start);
    switch(stype)
    {
        case INSERTION_SORT:
            InsertionSort(arr, SIZE);
            break;
        case MERGE_SORT:
            MergeSort(arr, 0, SIZE-1);
            break;
        case QUICK_SORT:
            QuickSort(arr, 0, SIZE-1);
			break;
		case COUNT_SORT:
			CountSort(arr, SIZE);
			break;
        default:
            break;
    }
	CheckTime(&timer->end);


	GetDiff(timer);
	PrintTimer(timer);

    FILE *ofp = fopen(argv[3], "w");
    if(ofp == NULL)
    {
        std::cerr << "Cannot open output file" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < SIZE; i++)
    {
        fprintf(ofp, "%u\n", arr[i]);
    }

    fclose(ifp);
    fclose(ofp);
    
    if(CheckSorting(arr, SIZE) == false)
        exit(EXIT_FAILURE);

    return 0;
}
