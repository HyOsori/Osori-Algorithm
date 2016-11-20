#include "Vector.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

Vector::Vector(int size){
	this->size=0;
	capacity = size;
	elements = (int*)malloc(sizeof(int)*capacity);
}
void Vector::push_back(int elem){
	if(size==capacity){
		resize();
	}
	elements[size++]=elem;
	std::cout <<elem<<"is added"<<std::endl;
}
int Vector::at(uint64_t idx){
	std::cout<<"Index "<<idx<<" : "<<elements[idx]<<std::endl;
	return elements[idx];
}
void Vector::resize(){
	int* tmp;
	int i=0;
	capacity*=2;
	tmp = (int*)malloc(sizeof(int)*capacity);
//	std::for_each(elements,elements+size,tmp);
	for(i=0;i<size;i++){
		tmp[i]=elements[i];
	}
	elements = tmp;
	std::cout<<"resize operation : "<<size<<"-->"<<capacity<<std::endl;
}
	
