// math_operations.h
#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

// Function to Add two numbers and return the sum
int Add(int *a, int *b);

// Function to Add two numbers and return the sum through the third pointer argument  
void AddVal(int *a, int *b, int *result);

// Function to Swap the value of two integers
void Swap(int *a, int *b);

// Function to Generate the factorial of a number using recursion
void Factorial(int *a, int *result);

#endif // MATH_OPERATIONS_H
