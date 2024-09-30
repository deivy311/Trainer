#include "functions.h"

// Function to add two numbers and return the result through a reference parameter
void Add(int a, int b, int &result) {
    result = a + b;
}

// Function to find the factorial of a number and return it through a reference parameter
void Factorial(int a, int &result) {
    result = 1;
    for (int i = 1; i <= a; ++i) {
        result *= i;
    }
}

// Function to swap two numbers using reference arguments
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
