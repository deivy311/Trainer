#include <iostream>

// Implement the following functions using ((pointer)) arguments only


// Function to add two integers and return the sum
int Add(int *a, int *b) {
    return *a + *b;
}

// Function to add two integers and store the result in a third pointer
void AddVal(int *a, int *b, int *result) {
    *result = *a + *b;
}

// Function to swap the values of two integers
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate the factorial of a number and store the result
void Factorial(int *a, int *result) {
    *result = 1;
    for (int i = 1; i <= *a; ++i) {
        *result *= i;
    }
}

int main() {
    int x = 1, y = 2;
    int sum = 0, fact = 0;

    // Using Add function
    std::cout << "Summation of " << x << " and " << y << " is: " << Add(&x, &y) << std::endl;

    // Using AddVal function
    AddVal(&x, &y, &sum);
    std::cout << "Summation of " << x << " and " << y << " using AddVal is: " << sum << std::endl;

    // Using Swap function
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(&x, &y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    // Using Factorial function
    Factorial(&x, &fact);
    std::cout << "Factorial of " << x << " is: " << fact << std::endl;

    return 0;
}
