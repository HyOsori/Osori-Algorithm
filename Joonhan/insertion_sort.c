#include <stdio.h>

void insert_sort(int arr[], int length);
void print_arr(int arr[], int length);
void swap(int *a, int *b);

int main(int argc, char *argv[]){
    int arr[10];
    int length =10;
    for(int i=0;i<length;i++)
        scanf("%d",&arr[i]);
    print_arr(arr, length);
    insert_sort(arr,length);
    print_arr(arr,length);
    return 0;
}

void insert_sort(int arr[], int length){
    for(int i=1; i<length;i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1])
                swap(&arr[j],&arr[j-1]);
        }
    }
}

void print_arr(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

