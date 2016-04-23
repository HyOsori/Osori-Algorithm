//
//  main.cpp
//  [Algorithm]Sorting
//
//  Created by 장형원 on 2016. 4. 8..
//  Copyright © 2016년 jhw. All rights reserved.
//

#include <iostream>
#include <string.h>

typedef enum {ERROR, INSERTION_SORT, MERGE_SORT} SORT_TYPE;

unsigned int SIZE = 1000000;

void usage()
{
    std::cerr << "Usage : <sort-type> <input-file> <output-file>" << std::endl;
}

bool CheckSorting(int *arr, unsigned int size)
{
    unsigned int i;

    for(i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            std::cerr << "Sorting Failure  " << std::endl; 
            return false;
        }
    }

    return true;
}

void InsertionSort(int *arr, unsigned int size)
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

void Merge(int *arr, unsigned int start, unsigned int mid, unsigned int end)
{
    int *temp = (int *)malloc(sizeof(int)*(end - start + 1));
    unsigned int i = start;
    unsigned int j = mid + 1;
    unsigned int k = 0;

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

void MergeSort(int *arr, unsigned int start, unsigned int end)
{
    if(start >= end)
        return;

    unsigned int mid = (start + end)/2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, start, mid, end);

}

SORT_TYPE GetSortType(const char * sname)
{
    if(strcmp(sname, "InsertionSort") == 0)
        return INSERTION_SORT;
    if(strcmp(sname, "MergeSort") == 0)
        return MERGE_SORT;

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
    
    unsigned int i = 0;
    int arr[SIZE];

    while(!feof(ifp))
    {
        fscanf(ifp, "%u", &arr[i]);
        i++;
    }
    
    switch(stype)
    {
        case INSERTION_SORT:
            InsertionSort(arr, SIZE);
            break;
        case MERGE_SORT:
            MergeSort(arr, 0, SIZE-1);
            break;
        default:
            break;
    }
    //InsertionSort(arr, SIZE);
    //MergeSort(arr, 0, SIZE-1);
    if(CheckSorting(arr, SIZE) == false)
        exit(EXIT_FAILURE);


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
    
    return 0;
}
