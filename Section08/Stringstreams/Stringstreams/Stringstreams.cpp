#include <iostream>
#include <sstream>
int main() {
	
	// int a{5}, b{6} ;
	// int sum = a + b ;
	// //std::cout << "Sum of " << a << " & " << b << " is :" << sum << std::endl;

	// std::stringstream ss ;
	// ss << "Sum of " << a << " & " << b << " is :" << sum << std::endl;
	// std::string s = ss.str() ;
	// std::cout << s << std::endl;

	// ss.str("") ;
	// ss << sum ;
	// auto ssum = std::to_string(sum) ;
	// std::cout << ssum << std::endl;
	


////////////////////////////////////////////////////////////

	std::string data = "12 89 21" ;
	int a ;
	std::stringstream ss ;  //provide insertions & extraction operators (read + write)
	ss.str(data) ;
	while(ss >> a) {
		std::cout << a << std::endl; 
	}
	int x = std::stoi("54") ;  // convert the string to integer
	std::cout << x << std::endl;
	return 0 ;
	
	// std::istringstream is ;  // only extraction operator >> // only read

	// std::ostringstream os ;  // only insertion operator <<>>>> // only write


}