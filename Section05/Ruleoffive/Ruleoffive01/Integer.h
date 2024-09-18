#pragma once
#include <iostream>
class Integer {
	int *m_pInt;

public:
	//Default constructor
	Integer();

	//Parameterized constructor
	Integer(int value);


	

	//Copy constructor  (L-value reference)
	Integer(const Integer &obj);

	//Move constructor (R-value)
	Integer(Integer &&obj);



/////////////// operators


	//Copy assignment  
	Integer & operator=(const Integer &obj) ;

	//Move assignment
	Integer & operator=(Integer && obj) ;

	int GetValue()const;
	void SetValue(int value);
	~Integer();

};
