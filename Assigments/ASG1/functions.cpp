#include "functions.h"

// Function to add two integers and return the sum (pointers are const because they do not modify data)
int Add(const int *a, const int *b) {
    return *a + *b;
}

// Function to add two integers and store the result in a third pointer (input pointers are const)
void AddVal(const int *a, const int *b, int *result) {
    *result = *a + *b;
}

// Function to swap the values of two integers (pointers are not const because they modify the values)
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate the factorial using a loop (input pointer is const)
void FactorialLoop(const int *a, int *result) {
    *result = 1;
    for (int i = 1; i <= *a; ++i) {
        *result *= i;
    }
}

// Helper function to compute factorial recursively (input is not a pointer)
int FactorialHelper(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * FactorialHelper(n - 1);
}

// Function to calculate the factorial using recursion (input pointer is const)
void FactorialRecursive(const int *a, int *result) {
    *result = FactorialHelper(*a);
}
