#include <iostream>
#include "Integer.h"
int main()
{
 //declare and inilialize x with 0
 Integer x;
 // declare and inilialize x with 3
 Integer y(3);
 // copy x (memory and value) to variable z
 Integer z(x);

 std::cout << "value of x is " << x.GetValue() << std::endl;
 std::cout << "value of y is " << y.GetValue() << std::endl;
 std::cout << "value of z is " << z.GetValue() << std::endl;
  
 x.SetValue(10);
 ++x;
 std::cout << "value of x after pre-increament is  " << x.GetValue() << std::endl;
 x++;
 std::cout << "value of x after post-increament is  " << x.GetValue() << std::endl;

return 0;

}
