#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

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
    
    printf("list push back test\n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        list_push_back(list, &arr[i]);
        printf("list push backed: %llu\r", list->count);
    }

}
