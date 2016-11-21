#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdint.h>

class Vector {
	public:
		Vector(uint64_t capacity);
		Vector(uint64_t size, uint64_t capacity, int *elements);
		void push_back(int elem);
		int at(uint64_t idx);
		void resize();
	private:	
		int *elements;
		uint64_t size;
		uint64_t capacity;
};
#endif
