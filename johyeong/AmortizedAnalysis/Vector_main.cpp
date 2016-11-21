#include "Vector.h"
#include <iostream>
#include <stdlib.h>

int main(){
	Vector test(10);

	for(int i=0;i<20;i++)
		test.push_back(i);

	return 0;
}
