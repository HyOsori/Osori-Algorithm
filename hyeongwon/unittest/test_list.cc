#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int main(int argc, const char* argv[])
{
    int i;
    int arr[ARRAY_SIZE];

    srand(time(NULL));

    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }

    struct list* list = create_list();
    
    for(i = 0; i < ARRAY_SIZE; i++) {
        list_push_back(&arr[i]);
    }

    printf("list : %llu\n", list->count);

}
