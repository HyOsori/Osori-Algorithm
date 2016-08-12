#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y) {x=x^y; y=x^y; x=x^y;}

void usage(void)
{
    puts("Usage : test_generator <filename> <size>");
    puts("Example : ./test_generator input.txt 10000");
    puts("Warning : If you put too much number in size option,i\
            created file could be very large");
}

void swap(int* x, int* y)
{
    int t = *x;
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
//            swap(&arr[i], &arr[rand()%size]);
            SWAP(arr[i], arr[rand()%size]);
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
        fprintf(fp, "%d\n", arr[i]);
    }

    return 0;
}
