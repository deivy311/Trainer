#include <iostream>
#include <vector>
template <typename T>
T Add(T x, T y)
{ // return sum of two elements
    return x + y;
}

template <typename T>
T ArraySum(const T* pArr, size_t arrSize)
{ // returns the sum of the array elements
   
    T sum = 0; // Initialize to zero for the type
    for (size_t i = 0; i < arrSize; ++i) {
        sum += pArr[i];
    }
    return sum;
}

template <typename T>
T Max(const T* pArr, size_t arrSize)
{
    
    T max = pArr[0]; // Initialize with the first element
    for (size_t i = 1; i < arrSize; ++i)
    {
        if (pArr[i] > max)
        {
            max = pArr[i];
        }
    }
    return max;
}

template<typename T>
std::pair<T,T> MinMax(const T* pArr,size_t arrSize){

    T max = pArr[0];
    T min = pArr[0];

    for(T i=1;i<arrSize;++i){
        if(pArr[i] < min){
            min =pArr[i];
        }

         if(pArr[i] > max){
            max =pArr[i];
        }
    }

    return std::make_pair(min, max);
}



int main()
{
    //call add function
    std::cout << "The sum= " << Add(7.4f,3.1f) << std::endl;

     // Declare a raw array
     int arr[] = {1, 3, 8, 5, 4};
    
    // Calculate the size of the array
    size_t size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "the sum of all numbers in the array is " << ArraySum(arr,size) << std::endl;

    //call max function
    std::cout << "the maximum number in the array is " << Max(arr,size) << std::endl;


     // Call the MinMax function
    std::pair<int, int> result = MinMax(arr, size);

    // Print the results
    std::cout << "Min: " << result.first << std::endl;
    std::cout << "Max: " << result.second << std::endl;

    return 0;
}
