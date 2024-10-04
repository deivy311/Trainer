#include <iostream>

int main() {
    int x = 5;
    const int MAX = 12;
    
    // 1. Reference variables
    int &ref_x1 = x;            // Valid: ref_x1 can modify x
    const int &ref_x2 = x;      // Valid: ref_x2 is a reference to a const int
    
    // Try to modify x1 & x2 and see the compilation output
     ref_x1 = 10;  // This will compile, x will be 10
    //ref_x2 = 15;  // This will NOT compile, as ref_x2 is a reference to const
    
    // 2. Pointer declarations
    const int *ptr1 = &x;      // Valid: ptr1 points to const int, can modify ptr1
    int *const ptr2 = &x;      // Valid: ptr2 is a constant pointer to int, cannot modify ptr2
    const int * const ptr3 = &x; // Valid: ptr3 is a constant pointer to a const int

    // Try to modify the pointer (e.g., ptr1) and the pointee value (e.g., *ptr1)
    // *ptr1 = 20; // This will NOT compile, cannot modify the pointee value
    // ptr1 = &MAX; // This will compile, ptr1 can point to another address
    
    // 3. Validating pointer declarations
    const int *ptr4 = &MAX;    // Valid: ptr4 points to const int
    // int *ptr5 = &MAX;        // Invalid: cannot assign to non-const pointer
    
    const int &r1 = ref_x1;    // Valid: r1 refers to ref_x1
    // int &r2 = ref_x2;        // Invalid: cannot assign a non-const reference to a const reference
    
    // 4. Reference to pointers
    // int *&p_ref1 = ptr1;      // Invalid: ptr1 is a pointer to const int
    int *const &p_ref2 = ptr2; // Valid: p_ref2 is a reference to a constant pointer

    // Output for testing
    std::cout << "x: " << x << ", MAX: " << MAX << std::endl;

    return 0;
}
