#include <iostream>

int main()
{

    // Try to modify x1 & x2 and see the compilation output
    int x = 10;
    const int MAX = 12;
    // ref_x1 is a reference to a non-const int, so it can be modified.
    int &ref_x1 = x;
    // ref_x2 is a reference to a const int, so the value it refers to cannot be modified.
    const int &ref_x2 = x;
    std::cout << ref_x1 << std::endl;
    std::cout << ref_x2 << std::endl;

    // Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x;       // ptr1 points to a const int, so the value of x can't be modified through ptr1
    int *const ptr2 = &x;       // ptr2 is a constant pointer to an int, so you can't change the address ptr2 holds, but you can modify the value it points to
    const int * const ptr3 = &x ;// ptr3 is a constant pointer to a constant int, so neither the address nor the value it points to can be modified

    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;
    std::cout << *ptr3 << std::endl;

    // Find which declarations are valid. If invalid, correct the declaration
    //const int *ptr3 = &MAX; // Valid
    const int *ptr4 = &MAX; // Corrected: ptr4 now points to a constant int

    const int &r1 = ref_x1; // Valid
    const int &r2 = ref_x2; // Corrected: r2 is now a const reference to ref_x2

    const int *&p_ref1 = ptr1; // Corrected: p_ref1 is now a reference to a const int pointer
    int *const &p_ref2 = ptr2; // Corrected: p_ref2 is now a reference to a constant pointer to int

    return 0;
}
