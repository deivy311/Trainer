#pragma once
#include <iostream>
class Integer
{
    int *value;

public:
    //Default constructor
	Integer();
	//Parameterized constructor
	Integer(int val);
	//Copy constructor
	Integer(const Integer& obj);
	//Move constructor
	Integer(Integer&& obj);
	int GetValue()const;
	void SetValue(int val);
	~Integer();

    //overloading operator
    Integer & operator++();
    Integer operator++(int);
};