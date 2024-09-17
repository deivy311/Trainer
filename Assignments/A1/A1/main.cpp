#include <iostream>

int Add(int *a, int *b) {
    return *a + *b;

}

void AddVal(int *a, int *b, int *result){
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


int main() {

    int a = 3, b =7, res=0;
    int add = Add(&a,&b);
    std::cout << "Add two numbers and return the sum: " << add << std::endl;
    
    AddVal(&a,&b,&res);
    std::cout << "Add two numbers and return the sum through the third pointer argument: " << res << std::endl;

    Swap(&a,&b);
    std::cout << "Swap the value of two integers. a = " << a << ", b = " << b << std::endl;
    

    Factorial(&a, &res);
    std::cout << "Generate the factorial of a number and return that through the second pointer argument:" << res << std::endl;
}

/* int Add(int *a, int *b) ;    //Add two numbers and return the sum
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument
*/