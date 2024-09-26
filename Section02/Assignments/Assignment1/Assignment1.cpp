#include <iostream>  // Required for cout
using namespace std;

// Function to add two numbers and return the sum
int Add(int *a, int *b) {
    return *a + *b;
}

// Function to add two numbers and return the sum through the third pointer argument
void AddVal(int *a, int *b, int *result) {
    *result = *a + *b;
}

// Function to swap the values of two integers
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate the factorial of a number and return that through the second pointer argument
void Factorial(int *a, int *result) {
    int fact = 1;
    for (int i = 1; i <= *a; i++) {
        fact *= i;
    }
    *result = fact;
}

// Example usage
int main() {
    int x = 10, y = 20, result;

    // Example for Add
    std::cout << "Add: " << Add(&x, &y) << std::endl;

    // Example for AddVal
    AddVal(&x, &y, &result);
    std::cout << "AddVal: " << result << std::endl;

    // Example for Swap
    Swap(&x, &y);
    std::cout << "Swap: x = " << x << ", y = " << y << std::endl;

    // Example for Factorial
    int num = 5;
    Factorial(&num, &result);
    std::cout << "Factorial: " << result << std::endl;

    return 0;
}
