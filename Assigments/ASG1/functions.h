// add a consta to the pointers in input functions 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function to add two integers and return the sum (input pointers are const)
int Add(const int *a, const int *b);

// Function to add two integers and store the result in a third pointer (input pointers are const)
void AddVal(const int *a, const int *b, int *result);

// Function to swap the values of two integers (pointers are not const because they modify the data)
void Swap(int *a, int *b);

// Function to calculate the factorial using a loop (input pointer is const)
void FactorialLoop(const int *a, int *result);

// Function to calculate the factorial using recursion (input pointer is const)
void FactorialRecursive(const int *a, int *result);

#endif // FUNCTIONS_H
