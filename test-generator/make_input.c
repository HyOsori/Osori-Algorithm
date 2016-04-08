#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define S_SIZE 10000
#define M_SIZE 100000
#define L_SIZE 1000000

unsigned int SIZE;

void usage()
{
	puts("Usage : make_input <scale> <input-file>");
}

void cmd(const char *str)
{

	if(!strcmp(str, "S") || !strcmp(str, "small"))
	{
		SIZE = S_SIZE;
	} 
	else if(!strcmp(str, "M") || !strcmp(str, "medium"))
	{
		SIZE = M_SIZE;
	}
	else if(!strcmp(str, "L") || !strcmp(str, "large"))
	{
		SIZE = L_SIZE;
	}
	else
	{
		puts("Error : Wrong scale input");
		exit(-1);
	}

}

int main(int argc, const char* argv[])
{
	srand( (unsigned int)time(NULL) );

	if(argc != 3)
	{
		usage();
		exit(-1);
	}

	cmd(argv[1]);
	
	unsigned int i;

	FILE *fp = fopen(argv[2], "w");
	if(!fp)
	{	
		puts("Error : Cannot open input-file");
		exit(-1);
	}
	
	for(i = 0; i < SIZE; i++)
	{
		fprintf(fp, "%u ", rand());
	}

	return 0;
}






