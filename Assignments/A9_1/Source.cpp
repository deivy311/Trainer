
/*
Convert the following functions into templates

	int Add(int x,int y) ; //Return the sum of two elements

	int ArraySum(const int *pArr, size_t arrSize); //Returns the sum of array elements

	int Max(const int *pArr, size_t arrSize) ; //Return the largest element in the array

	std::pair<int,int> MinMax(const int *pArr, size_t arrSize) ; //Return the smallest and largest element in a pair

Take care to avoid copies of user-defined objects wherever applicable.
*/

#include <iostream>
#include <utility>

//    int Add(int x,int y) ; //Return the sum of two elements
template <typename T>
T Add(const T &x, const T &y)
{
	return x + y;
}

//    int ArraySum(const int *pArr, size_t arrSize); //Returns the sum of array elements
template <typename T>
T ArraySum(const T *pArr, size_t arrSize)
{
	T sum = 0;
	for (size_t i = 0; i < arrSize; ++i)
	{
		sum += pArr[i];
	}
	return sum;
}

// int Max(const int *pArr, size_t arrSize) ; //Return the largest element in the array
template <typename T>
T Max(const T *pArr, size_t arrSize)
{
	T max = pArr[0];
	for (size_t i = 1; i < arrSize; ++i)
	{
		if (pArr[i] > max)
		{
			max = pArr[i];
		}
	}
	return max;
}

// std::pair<int,int> MinMax(const int *pArr, size_t arrSize) ; //Return the smallest and largest element in a pair
template <typename T>
std::pair<T, T> MinMax(const T *pArr, size_t arrSize)
{
	T min = pArr[0];
	T max = pArr[0];
	for (size_t i = 1; i < arrSize; ++i)
	{
		if (pArr[i] < min)
		{
			min = pArr[i];
		}
		if (pArr[i] > max)
		{
			max = pArr[i];
		}
	}
	return std::make_pair(min, max);
}

int main()
{
	int arr[] = {1, 2, 3, 4};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	// Testing
	std::cout << "Add 9, 6 = " << Add(9, 6) << std::endl;
	std::cout << "ArraySum arr = " << ArraySum(arr, size) << std::endl;
	std::cout << "Max = " << Max(arr, size) << std::endl;

	// Test MinMax function
	auto minMaxPair = MinMax(arr, size);
	std::cout << "Min = " << minMaxPair.first << " .. Max = " << minMaxPair.second << std::endl;

	return 0;
}
