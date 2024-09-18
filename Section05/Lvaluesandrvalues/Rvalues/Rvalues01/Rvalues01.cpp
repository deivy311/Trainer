#include <iostream>

//Returns r-value
int Add(int x, int y) {
	return x + y;
}
//Return l-value
int & Transform(int &x) {
	x *= x;
	return x;
}

//L-value Reference 
void Print(int &x) {
	std::cout << "Print(int&)" << std::endl; 
}

//L-value Reference 
void Print(const int &x) {
	std::cout << "Print(const int&)" << std::endl;

}

//R-value reference 
void Print(int &&x) {
	std::cout << "Print(int &&)" << std::endl;
}


int main() {
	//x is lvalue
	int x = 10;
	
	//ref is l-value reference  (after = is a string/letter)
	int &ref = x ;
	//Transform returns an l-value
	int &ref2 = Transform(x) ;
	//Binds to function that accepts l-value reference
	Print(x);

	
	

	//rv is r-value reference (after = is a number)
	int &&rv = 8 ;
	
	//Add returns a temporary (r-value)
	int &&rv2 = Add(3,5) ;
	//Binds to function that accepts a temporary, i.e. r-value reference
	Print(3);
	return 0;
}

