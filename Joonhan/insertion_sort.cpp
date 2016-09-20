//2015004557_박준한_A

#include <stdio.h>
#define swap(t,x,y) {t tmp=x; x=y; y=tmp;}

void insert_sort(int arr[], int length);
void print_arr(int arr[], int length);

int main(int argc, char *argv[]){
    
    scanf("%d",&argc);
    int arr[argc];
    for(int i=0;i<argc;i++)
        scanf("%d",&arr[i]);
    insert_sort(arr,argc);
    print_arr(arr,argc);
    return 0;
}

void insert_sort(int arr[], int argc){
    for (int i = 1; i < argc; i++)
    {
        int j,temp;
        temp = arr[(j = i)];
        while ((--j >= 0) && (temp > arr[j])){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }}

void print_arr(int arr[], int argc){
    for(int i=0; i<argc; i++){
        printf("%d\n",arr[i]);
    }
}