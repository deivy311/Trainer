#include <iostream>
//Add two numbers and return the sum
int Add(int *a, int *b){
	return *a + *b;
}  
//Add two numbers and return the sum through the third pointer argument
void AddVal(int *a, int *b, int *result){
    *result = *a + *b;
} 
//Swap the value of two integers
void Swap(int *a, int *b) {
int c=*a;
*a = *b;
*b = c;
}
//Generate the factorial of a number and return that through the second pointer argument
void Factorial(int *a, int *result){
    *result = 1;
    for (int i = 1; i <= *a; ++i) {
        *result *= i;
    }
}  

int main() {
    int x = 8, y = 9, result = 0;
    std::cout << "Assignment1-Pointers " << std::endl;

    // Add
    std::cout << "Add(8, 9): " << Add(&x, &y) << std::endl;

    // AddVal
    AddVal(&x, &y, &result);
    std::cout << "AddVal(8, 9): " << result << std::endl;

    // Swap
    Swap(&x, &y);
    std::cout << "Swap: x = " << x << ", y = " << y << std::endl;

    // Factorial
    Factorial(&x, &result);
    std::cout << "Factorial(9): " << result << std::endl;

    return 0;
}
