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

void Print(int &x) {
	std::cout << "Print(int&)" << std::endl; 
}
void Print(const int &x) {
	std::cout << "Print(const int&)" << std::endl;

}

//accepet r-value reference
void Print(int &&x) {
	std::cout << "Print(int &&)" << std::endl;
}
int main() {
	// //x is lvalue
	// int x = 10;
	
	// //ref is l-value reference
	// int &ref = x ;
	// //Transform returns an l-value
	// int &ref2 = Transform(x) ;
	// //Binds to function that accepts l-value reference
	// Print(x);
	

	// //rv is r-value reference
	// int &&rv = 8 ;
	
	// //Add returns a temporary (r-value)
	// int &&rv2 = Add(3,5) ;
	// //Binds to function that accepts a temporary, i.e. r-value reference
	// Print(3);
	// return 0;


	// my practice below ------------------------

   int &&r1 = 10;
   int &&r2 = Add(3,2);
   int x =0; //l value 
   Print(x); // call l value function
   Print(3);
   //int &&r3 = x;//connot assign l value to a r value

   int &ref = Transform(x);
   const int &ref2 = 3;

   
   return 0;

}

