
/*
For the functions in questions 2,3 & 4 in Assignment I above,

	Modify to accept array by reference.

	Specialize for an array of strings (const char *). Observe, the limitations.

	Specialize for an array of std::strings. Compare with the previous implementation.

	Define the specialized functions in a .h file and include it in multiple source (.cpp) files. Observe what happens.
*/
#include <iostream>
#include "functions.h"

int main()
{
	// Test int array
	int arr[] = {1, 2, 3, 4};
	std::cout << "ArraySum arr = " << ArraySum(arr) << std::endl;
	std::cout << "Max arr = " << Max(arr) << std::endl;
	auto minMaxPair = MinMax(arr);
	std::cout << "Min = " << minMaxPair.first << ", Max = " << minMaxPair.second << std::endl;

	// Test const char* array
	const char *strArr[] = {"red", "blue", "while", "green"};
	std::cout << "Max of const char* arr = " << Max(strArr) << std::endl;
	auto strMinMax = MinMax(strArr);
	std::cout << "Min = " << strMinMax.first << ", Max = " << strMinMax.second << std::endl;

	// Test std::string array
	std::string stringArr[] = {"red", "blue", "while", "green"};
	std::cout << "Max of std::string arr = " << Max(stringArr) << std::endl;
	auto stringMinMax = MinMax(stringArr);
	std::cout << "Min = " << stringMinMax.first << ", Max = " << stringMinMax.second << std::endl;

	return 0;
}
