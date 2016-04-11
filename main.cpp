//
//  main.cpp
//  [Algorithm]Sorting
//
//  Created by 장형원 on 2016. 4. 8..
//  Copyright © 2016년 jhw. All rights reserved.
//

#include <iostream>

unsigned int SIZE = 10000;

void usage()
{
    std::cerr << "Usage : sort <input-file> <output-file>" << std::endl;
}

void InsertionSort(int *arr, unsigned int n)
{
    int key, i, j;

    for(j = 1; j < n; j++)
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

int main(int argc, const char * argv[]) {
    
    if(argc != 3)
    {
        usage();
        exit(EXIT_FAILURE);
    }
    
    FILE *ifp = fopen(argv[1], "r");
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
    
    InsertionSort(arr, SIZE);
    
    FILE *ofp = fopen(argv[2], "w");
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
