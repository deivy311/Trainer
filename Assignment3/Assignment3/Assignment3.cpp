#include <iostream>

int main()
{

    // Try to modify x1 & x2 and see the compilation output
    int x = 10;
    const int MAX = 12;
    int &ref_x1 = x;
    const int &ref_x2 = x;
    std::cout << ref_x1 << std::endl;
    std::cout << ref_x2 << std::endl;

//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
const int *ptr1 = &x ;
int *const ptr2 = &x ;
const int * const ptr3 = &x ;

std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;
        std::cout << ptr3 << std::endl;

//Find which declarations are valid. If invalid, correct the declaration
const int *ptr3 = &MAX ;
const int *ptr4 = &MAX ;
 
const int &r1 = ref_x1 ;
const int *r2 = &ref_x2 ;
 
const int *p_ref1 = ptr1 ;
const int *p_ref2 = ptr2 ;

    return 0;

}
