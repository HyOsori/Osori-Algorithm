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
    for(int i=1; i<argc;i++){
        for(int j=i; j>0; j--){
            if(arr[j]>arr[j-1])
                swap(int, arr[j],arr[j-1]);
        }
    }
}

void print_arr(int arr[], int argc){
    for(int i=0; i<argc; i++){
        printf("%d\n",arr[i]);
    }
}