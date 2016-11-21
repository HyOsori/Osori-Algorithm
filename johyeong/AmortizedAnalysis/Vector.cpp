#include "Vector.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Vector::Vector(uint64_t capacity){
	this->size = 0;
	this->capacity = capacity;
	this->elements = new int[this->capacity];
}
Vector::Vector(uint64_t size, uint64_t capacity, int *elements){
	this->size = size;
	this->capacity = capacity;
	this->elements = new int[this->capacity];

	for(int i=0;i<size;i++)
		this->elements[i] = elements[i];

}
void Vector::push_back(int elem){
	if(size==capacity)
		resize();

	elements[size++] = elem;
	cout << elem << "is added!" << endl;
}
int Vector::at(uint64_t idx){
	cout << "INDEX : " << idx << "VALUE : " << elements[idx] << endl;
	
	return elements[idx];
}
void Vector::resize(){
	int *new_elements;

	capacity *= 2;
	new_elements = new int[capacity];

	for(int i=0;i<size;i++)
		new_elements[i] = elements[i];
	
	elements = new_elements;
	delete[] new_elements;

	cout << "Resize Operation : Capacity[" << capacity << "] " << "size[" << size << "]" << endl; 
}
