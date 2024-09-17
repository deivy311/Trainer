#include <iostream>
#include <vector>
//Assig 1
     //Function to Add two numbers and return the sum
    int Add(int *a, int *b){   
      return *a + *b;
      }
    //Function to Add two numbers and return the sum through the third pointer argument  
    void AddVal(int *a, int *b, int *result){ 
      *result = *a + *b;
      }
    //Function to Swap the value of two integers
    void Swap(int *a, int *b){  
      int temp = *a;
      *a= *b;
      *b = temp;
      }
    //Function to Generate the factorial of a number and return that through the second pointer argument
    void Factorial(int *a, int *result){
      *result = 1;
      for(int i = 2; i<= *a; ++i){
        *result *i;
      }
    }
      //Assig 1 end
int main(int argc, char *argv[])
{
//Assig 1
  int x = 3, y = 5, result= 0;

  //Add two numbers and return the sum
  std::cout<<"Add("<< x << ", "<<y<<") = "<< Add(&x,&y) << std::endl;

  //Example for AddVal function
  AddVal(&x , &y, &result);
  std::cout << "AddVal(" << x << ", " << y << ") -> result = " << result << std::endl;

  //Example ot the Swap value of two integers
  std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
  Swap(&x, &y);
  std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;
  
  // Example for Factorial function
  int num = 4;
  Factorial(&num, &result);
  std::cout << "Factorial (" << num << ") =" << result << std::endl;

      //Assig 1 end
  return 0;
}
