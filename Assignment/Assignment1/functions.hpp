#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

// Function to add two numbers and return the sum
int Add(const int *a, const int *b);

// Function to add two numbers and return the sum through the third pointer argument
void AddVal(const int *a, const int *b, int *result);

// Function to swap the values of two integers
void Swap(int *a, int *b);

// Function to generate the factorial of a number and return that through the second pointer argument
void Factorial(int *a, int *result);

#endif // FUNCTIONS_HPP
