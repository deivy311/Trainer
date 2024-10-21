#include <iostream>
#include <vector>
#include <cstring>
#include "specialized_functions.h" // Include specialized_functions header file

template <typename T>
T Add(T x, T y)
{ // return sum of two elements
    return x + y;
}

template <typename T, size_t arrSize>
T ArraySum(const T (&pArr)[arrSize])
{ // returns the sum of the array elements

    T sum = 0; // Initialize to zero for the type
    for (int i = 0; i < arrSize; ++i)
    {
        sum += pArr[i];
    }
    return sum;
}


template <typename T,size_t arrSize>
T Max(const T (&pArr)[arrSize])
{

    T max = pArr[0]; // Initialize with the first element
    for (int i = 1; i < arrSize; ++i)
    {
        if (pArr[i] > max)
        {
            max = pArr[i];
        }
    }
    return max;
}


template <typename T, size_t arrSize>
std::pair<T, T> MinMax(const T (&pArr)[arrSize])
{

    T max = pArr[0];
    T min = pArr[0];

    for (int i = 1; i < arrSize; ++i)
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



template <typename T>
T FindMax(T x, T y)
{
    T max = 0;
    if (x > y)
    {
        max = x;
    }
    else
    {
        max = y;
    }

    return max;
}

int main()
{
    // call add function
    std::cout << "The sum= " << Add(2.3f, 4.6f) << std::endl;

    // Declare a raw array
    float arr[] = {1.5f, 11, -0.9f, 17.0f, 3.14f};

    // Calculate the size of the array
    size_t size = sizeof(arr) / sizeof(arr[0]);
    // call  ArraySum(const T (&pArr)[arrSize]) function
    std::cout << "the sum of all numbers in the array is " << ArraySum(arr) << std::endl;

    // call  Max(const T (&pArr)[arrSize]) function
    std::cout << "the maximum number in the array is " << Max(arr) << std::endl;

    // Call the std::pair<T, T> MinMax(const T (&pArr)[arrSize]) function
    std::pair<float, float> result = MinMax(arr);

    // Print the results
    std::cout << "Min: " << result.first << std::endl;
    std::cout << "Max: " << result.second << std::endl;

    // call  FindMax(T x, T y)
    float max = FindMax<float>(6,6.9f); 
    std::cout << "Maximum number for the two inputs is: " << max << std::endl;

    std::cout << "-------Test with array of strings (const char *)--------" << std::endl;

    const char* arr2[] = {"Hello", "World", "!"}; // This is an array with 3 elements
    // Call the specialized function
    // call int ArraySum(const char* const (&arr)[N]) function
    std::cout << "The sum is: " << ArraySum(arr2) << std::endl;  
    // call const char* Max(const char* const (&arr)[N]) function
    const char* maxStr_2 = Max(arr2);
    std::cout << "The maximum string is: " << maxStr_2 << std::endl;

    // Call the std::pair<const char*, const char*> MinMax(const char* const (&arr)[N]) function
    std::pair<const char*, const char*> result2 = MinMax(arr2);

    // Output the results2
    std::cout << "The minimum string is: " << result2.first << std::endl;
    std::cout << "The maximum string is: " << result2.second << std::endl;

    std::cout << "-------Test with array of std::strings--------" << std::endl;
    // Declare an array of std::string
    std::string arr3[] = {"apple", "orange", "banana", "pear"};

    // call int ArraySum(const std::string (&arr)[N]) function
    std::cout << "The sum is: " << ArraySum(arr3) << std::endl; 

     // Call the specialized std::string Max(const std::string(&arr)[N]) function
    std::string maxStr_3 = Max(arr3);

    // Output the result
    std::cout << "The maximum string is: " << maxStr_3 << std::endl;

    // Call the specialized std::pair<std::string, std::string> MinMax(const std::string (&arr)[N]) function
    std::pair<std::string, std::string> result3 = MinMax(arr3);

    // Output the results
    std::cout << "The minimum string is: " << result3.first << std::endl;
    std::cout << "The maximum string is: " << result3.second << std::endl;
    return 0;
}
