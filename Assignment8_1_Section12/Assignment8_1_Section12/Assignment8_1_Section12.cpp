#include <iostream>
#include <vector>
template <typename T>
T Add(T x, T y)
{ // return sum of two elements
    return x + y;
}

template <typename T>
T ArraySum(const T *pArr, size_t arrSize)
{ // returns the sum of the array elements

    T sum = 0; // Initialize to zero for the type
    for (int i = 0; i < arrSize; ++i)
    {
        sum += pArr[i];
    }
    return sum;
}

template <typename T>
T Max(const T *pArr, size_t arrSize)
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

template <typename T>
std::pair<T, T> MinMax(const T *pArr, size_t arrSize)
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
    float arr[] = {1.5f, 11, -0.5f, 10.0f, 3.14f};

    // Calculate the size of the array
    size_t size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "the sum of all numbers in the array is " << ArraySum(arr, size) << std::endl;

    // call max function
    std::cout << "the maximum number in the array is " << Max(arr, size) << std::endl;

    // Call the MinMax function
    std::pair<float, float> result = MinMax(arr, size);

    // Print the results
    std::cout << "Min: " << result.first << std::endl;
    std::cout << "Max: " << result.second << std::endl;

    float max = FindMax<float>(6,6.9f); 
    std::cout << "Maximum number for the two inputs is: " << max << std::endl;

    return 0;
}
