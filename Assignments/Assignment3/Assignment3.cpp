#include <iostream>

int main() {
    // Part 1: References and Modifications
    int x = 5;
    const int MAX = 12;

    // Try to modify x1 & x2 and see the compilation output
    int &ref_x1 = x;                // Valid - reference to a non-const int.
    std::cout << "int &ref_x1 = x:" << &ref_x1 << std::endl;

    const int &ref_x2 = x;          // Valid - reference to a const int.

    std::cout << "Initial value of x: " << x << std::endl;

    // Valid: modifying through non-const reference (ref_x1)
    ref_x1 = 10;
    std::cout << "After modifying ref_x1 (Valid): " << x << std::endl;

    // Invalid: modifying through const reference (ref_x2) will cause an error if uncommented
    // ref_x2 = 15; // Uncommenting this line will cause a compilation error

    // Part 2: Pointers and Modifications
    const int *ptr1 = &x;           // Valid - pointer to a const int.
    int *const ptr2 = &x;           // Valid - constant pointer to a non-const int.
    const int *const ptr3_1 = &x;   // Valid - constant pointer to a const int.
    const int *ptr3_2 = &MAX;       // Valid - pointer to a const int.

    // Valid: modifying the value pointed by ptr2 (pointee is not const)
    *ptr2 = 20;
    std::cout << "After modifying *ptr2 (Valid): " << *ptr2 << std::endl;

    // Invalid: trying to modify the value pointed by ptr1 (pointee is const)
    // *ptr1 = 25; // Uncommenting this line will cause a compilation error

    // Invalid: ptr2 is a constant pointer, we cannot change where it points
    // ptr2 = &MAX; // Uncommenting this line will cause a compilation error

    // Part 3: References to Pointers
    const int *&p_ref1 = ptr1;      // Valid - reference to a pointer to a const int.

    // Invalid: ptr2 is a constant pointer, so we need to declare the reference accordingly
    // const int*& p_ref2 = ptr2;   // Uncommenting this line will cause a compilation error
    int *const &p_ref2 = ptr2;      // Valid - reference to a constant pointer to int.

    // Final Output: print values to validate the declarations
    std::cout << "ptr1 points to: " << *ptr1 << " (Valid)" << std::endl;
    std::cout << "ptr2 points to: " << *ptr2 << " (Valid)" << std::endl;
    std::cout << "ptr3_1 points to: " << *ptr3_1 << " (Valid)" << std::endl;
    std::cout << "ptr3_2 points to: " << *ptr3_2 << " (Valid)" << std::endl;

    return 0;
}

