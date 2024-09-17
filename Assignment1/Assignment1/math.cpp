#include <iostream>
#include "math.h"
// Defination
int Add(int *a, int *b)
{ // Add two numbers and return the sum

    int sum = *a + *b;

    std::cout << "Sum is: " << sum << std::endl;
    return sum;
}

void AddVal(int *a, int *b, int *result) // Add two numbers and return the sum through the third pointer argument
{
    *result = *a + *b;
    std::cout << "Result is: " << *result << std::endl;
}

void Swap(int *a, int *b)
{ // Swap the value of two integers

    int temp = *a;
    *a = *b;
    *b = temp;
    
}

void Factorial(int *a, int *result)
{ // Generate the factorial of a number and return that through the second pointer argument

    *result = 1;
    for (int i = 1; i <= *a; i++)
    {
        *result = *result * i;
    }
     std::cout << "Factorial of: " << *a << " is " << *result << std::endl;
}