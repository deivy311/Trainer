// math_operations.cpp
#include "math_operations.h"

int Add(int *a, int *b) {   
    return *a + *b;
}

void AddVal(int *a, int *b, int *result) { 
    *result = *a + *b;
}

void Swap(int *a, int *b) {  
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Factorial(int *a, int *result) {
    if (*a <= 1) {
        *result = 1;  // Base case: factorial of 0 or 1 is 1
    } else {
        int temp = *a - 1;
        Factorial(&temp, result);   // Recursive call with a smaller number
        *result *= *a;              // Multiply the result with the current number
    }
}
