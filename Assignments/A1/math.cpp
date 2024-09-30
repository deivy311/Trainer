#include <iostream>
#include "math.h"

int Add(const int *a, const int *b){
    return *a + *b;

}

void AddVal(const int *a, const int *b, int *result){
    *result = *a + *b;
}

void Swap(int *a, int *b){
    int temp = *a; 
    *a = *b;
    *b = temp;
}  


void Factorial(int *a, int *result) {
    *result = 1;
    for (int i = 1; i <= *a; ++i) {
        *result *= i;
    }
}

void Factorial_recursive(int *a, int *result){ 

    if (*a <= 1){
        *result = 1;  
    }
    else {
        int temp = *a - 1;
        Factorial(&temp, result); 
        *result = *result * (*a); 
    }
}

