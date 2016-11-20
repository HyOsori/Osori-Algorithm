#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>
#include <stdint.h>

class Vector{
public:
	Vector(int size);
	void push_back(int elem);
	int at(uint64_t idx);
	void resize();
private:
	int* elements;
	uint64_t size;
	uint64_t capacity;
};
#endif
