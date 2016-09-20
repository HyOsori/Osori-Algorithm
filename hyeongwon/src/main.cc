#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "timer.h"

typedef enum {ERROR, INSERTION_SORT, MERGE_SORT, QUICK_SORT, COUNT_SORT} SORT_TYPE;

int SIZE = 10;

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
            MergeSort(arr, SIZE);
            break;
        case QUICK_SORT:
            QuickSort(arr, SIZE);
			break;
		case COUNT_SORT:
			CountingSort(arr, SIZE);
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
