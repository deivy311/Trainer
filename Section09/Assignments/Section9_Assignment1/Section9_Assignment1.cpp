// #include <iostream>
// #include "Savings.h"
// #include "Checking.h"
// #include "Transaction.h"
// #include <typeinfo>

// int main()
// {
// 	Checking ch("Bob", 100, 50);
// 	Transact(&ch);

//     return 0;
// }
 
#include <iostream>
using namespace std;

class Person{
  
  // declaring private class data members 
private:
  string name;
  int age;
  
public: 

  // declaring constructor
  Person()
  {
      cout<<"Default constructor is called"<<endl;
      name = "student";
      age = 12;
  }
  
  ~Person()
  {
	      cout<<"Default deconstructor is called"<<endl;
		  
  }
  // display function to print the class data members value 
  void display()
  {
      cout<<"Name of current object: "<<name<<endl;
      cout<<"Age of current object: "<<age<<endl;
  }
  
};
int main() 
{
    // creating object of class using default constructor
    Person obj;
    
    // printing class data members 
    obj.display();
    
    return 0;
}