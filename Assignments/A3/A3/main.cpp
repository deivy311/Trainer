#include <iostream>

int main() {

    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    const int &ref_x2 = x ;
    ref_x1 = 1; //works
    std::cout << ref_x1 << std::endl;
    //ref_x2 = 8; //doesn't work
    



    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x ;
    int y = 8;
    ptr1 = &y; //works 
    // ptr1 = 2; //doesn't work
    //std::cout << ptr1 << std::endl;

    int *const ptr2 = &x ;
    *ptr2 = 7; //works 
    //ptr2 = &y; //doesn't work
    std::cout << ptr2 << std::endl;

    const int * const ptr3 = &x;
    //*ptr3 = 7;   //doesn't work
    //ptr3 = &y;   //doesn't work
    std::cout << *ptr3 << std::endl;

    // Find which declarations are valid. If invalid, correct the declaration
    const int *ptr5 = &MAX;
    std::cout << *ptr5 << std::endl;

    const int *ptr4 = &MAX;

    const int &r1 = ref_x1; 
    const int &r2 = ref_x2; 

    const int *const &p_ref1 = ptr3; 
    const int *&p_ref2 = ptr4;       

    return 0;
}