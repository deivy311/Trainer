#include "functions.hpp"

// Function to add two numbers and return the sum
int Add(const int *a, const int *b) {
    return *a + *b;
}

// Function to add two numbers and return the sum through the third pointer argument
void AddVal(const int *a, const int *b, int *result) {
    *result = *a + *b;
}

// Function to swap the values of two integers
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate the factorial of a number
void Factorial(int *a, int *result) {
    if (*a < 0) {
        *result = 0; // Factorial is not defined for negative numbers
        return;
    }
    if (*a == 0 || *a == 1) {
        *result = 1; // Base case
        return;
    }
    int temp = *a; // Store the current value
    (*a)--; // Decrease the value for recursion
    Factorial(a, result); // Recursive call
    *result *= temp; // Multiply result with the current value
}
