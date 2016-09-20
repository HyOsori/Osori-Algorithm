#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SelectionSort(int arr[], int n, int m)
{
    int i, j, mid, tmp;
    
    for (i = 0; i<m; i++)
    {
        mid = i;
        
        for (j = i + 1; j<n; j++)
        {
            if (arr[j] < arr[mid])
                mid = j;
        }
        
        if (i != mid)
        {
            tmp = arr[mid];
            arr[mid] = arr[i];
            arr[i] = tmp;
        }
    }
}

int main(void)
{
    int i;
    int n, m;
    int * arr;
    
    scanf("%d %d", &n, &m);
    
    arr = (int*)malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); 
    }
    
    SelectionSort(arr, n, m);  
    
    
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]); 
    }
    
    free(arr);
    return 0;
}