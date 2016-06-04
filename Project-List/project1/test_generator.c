#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void usage()
{
    puts("Usage : test_generator <filename> <size>");
}

void swap(int* x, int* y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void shuffle(int* arr, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(rand()%2)
        {
            swap(&arr[i], &arr[rand()%size]);
        }
    }
}

int main(int argc, const char* argv[])
{
    srand( (unsigned int)time(NULL) );
    
    if(argc != 3) {
        usage();
        exit(-1);
    }

    FILE *fp = fopen(argv[1], "w");
    if(!fp)
    {       
            puts("Error : Cannot open input-file");
            exit(-1);
    }
    
    int size = atoi(argv[2]);
    int* arr = (int *)malloc(sizeof(int)*size);
    int i;

    for(i = 0; i < size; i++)
    {
            arr[i] = i;
    }

    shuffle(arr, size);

    for(i = 0; i < size; i++)
    {
            fprintf(fp, "%u\n", arr[i]);
    }

    return 0;
}
