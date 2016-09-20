#include <iostream>
#include <random>


void usage(void)
{
    std::cout << "Usage : test_generator <filename> <size>\n";
    std::cout << "Example : ./test_generator input.txt 10000\n";
    std::cout << "Warning : If you put too much number in size option, \
            created file could be very large\n";
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
        std::cout << "Error : Cannot open input-file\n";
        exit(-1);
    }
    
    int size = atoi(argv[2]);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, size);

    for(int i = 0; i < size; i++)
    {
        fprintf(fp, "%d\n", distr(generator));
    }

    return 0;
}
