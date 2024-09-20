#include "Integer.h"
#include <iostream>

Integer::Integer(){
    std::cout << "integer()" << std::endl;
    value = new int(0); // alllocate a memory for the integer and initialize to 0
}

Integer::Integer(int val){
    std::cout << "integer(int)" << std::endl;
    value = new int(val); // allocate a memory for the integer and initialize with val
}
//Copy constructor
Integer::Integer(const Integer& obj){
    std::cout << "Integer(const Integer &)" << std::endl;
    value = new int(*obj.value); // Deep copy of the integer value
}

//Move Constructor
Integer::Integer(Integer&& obj) {
	std::cout << "Integer(int&&)" << std::endl;
	value = obj.value; // steal the resource
	obj.value = nullptr; // nullify the moved from object to avoid double deletion
}

//get the value
int Integer::GetValue()const {
    return *value; 
}
//set the value
void Integer::SetValue(int val){
    *value = val;
}

//pre-increment
Integer& Integer::operator++() {
	++(*value);
	return *this; // return the incremented object
}

//post increment
Integer Integer::operator++(int) {
	Integer temp(*this); // use a copy constructor to make a copy
	++(*value);// increament the currnet obj
	return temp;// return before increment obj
}
//Destructor
Integer::~Integer(){
    std::cout << "~Integer()" << std::endl;
    delete value; // free the allocated memory
}