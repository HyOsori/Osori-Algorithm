#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(int arr[], int start, int mid, int end)
{
    int i, j, k;
    int a = mid - start + 1;
    int b = end - mid;
    
    int * left_array, *right_array;
    left_array = (int*)malloc(sizeof(int)*(a + 1));
    right_array = (int*)malloc(sizeof(int)*(b + 1));
    
    for (i = 0; i < a; i++)
    {
        left_array[i] = arr[start + i - 1];
    }
    for (i = 0; i < b; i++)
    {
        right_array[i] = arr[mid + i];
    }
    left_array[a] = 100000;
    right_array[b] = 100000;
    i = 0;
    j = 0;
    
    for (k = start - 1; k < end; k++)
    {
        if (left_array[i] <= right_array[j])
            arr[k] = left_array[i++];
        else
            arr[k] = right_array[j++];
    }
}

void Merge_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        Merge_sort(arr, start, mid);
        Merge_sort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}



int main(void)
{
    int i, n;
    int * arr;
    
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int)*(n + 1));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    
    Merge_sort(arr, 1, n);
    
    for (i = n-1; i>=0; --i)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
