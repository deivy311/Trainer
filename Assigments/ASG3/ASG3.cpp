#include <iostream>

int main() {
    // (1) Try to modify x1 & x2 and see the compilation output
    int x = 5;
    const int MAX = 12;
    int &ref_x1 = x;
    const int &ref_x2 = x;

    // Modifying ref_x1 is allowed but ref_x2 is causing error
    ref_x1 = 10;
    //ref_x2 = 15;
  

    // (2) Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x;  // Pointer to const int, can change pointer but not the value it points to
    int *const ptr2 = &x;  // Const pointer to int, can change value but not the pointer itself
    const int *const ptr3 = &x;  // Const pointer to const int, can't change pointer or value

/////////////////////////////////////////////////////////////////////////////////////////////

    // (3)) Find which declarations are valid. If invalid, correct the declaration
    const int *ptr3_valid = &MAX;  // Correct declaration
    // int *ptr4 = &MAX;  // This is invalid because MAX is const
    const int *ptr4 = &MAX;  // Corrected declaration

    const int &r1 = ref_x1;  // Valid declaration
    // int &r2 = ref_x2;  // Invalid, ref_x2 is const
    const int &r2 = ref_x2;  // Corrected declaration

    // int *&p_ref1 = ptr1;  // Invalid, ptr1 is const int*
    const int *&p_ref1 = ptr1;  // Corrected declaration

    // const int *&p_ref2 = ptr2;  // Invalid, ptr2 is int* const
    int *const &p_ref2 = ptr2;  // Corrected declaration

/////////////////////////////////////////////////////////////////////////////////////////////
    // Output some values to observe the effects
    std::cout << "x: " << x << std::endl;
    std::cout << "ref_x1: " << ref_x1 << std::endl;
    std::cout << "ref_x2: " << ref_x2 << std::endl;

    return 0;
}
