#include <iostream>

int main() {
    // Initial variable declarations
    int x = 5;
    const int MAX = 12;

    // Try to modify x1 & x2 and see the compilation output
    int &ref_x1 = x;          // A reference to a non-const int, this is modifiable.
    const int &ref_x2 = x;    // A const reference, this cannot modify the value of x.

    ref_x1 = 10;              // This is valid since ref_x1 is a non-const reference.
    // ref_x2 = 15;           // Invalid: Cannot modify x through ref_x2 because it's a const reference.

    std::cout << "x after ref_x1 modification: " << x << std::endl;
    // std::cout << "x after ref_x2 modification: " << x << std::endl;

    // Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x;     // ptr1 can point to another address, but the value *ptr1 cannot be changed.
    int *const ptr2 = &x;     // ptr2 is a constant pointer to int, meaning the pointer itself cannot change, but *ptr2 can.
    const int *const ptr3 = &x;  // ptr3 is a constant pointer to a constant int, so neither the pointer nor the value can change.

    // Modifying pointee and pointer
    ptr1 = &MAX;              // Valid: ptr1 can point to another int (const int), but *ptr1 cannot change.
    // *ptr1 = 20;            // Invalid: Cannot modify value pointed by ptr1, because it's a const int.

    // ptr2 = &MAX;           // Invalid: ptr2 is a constant pointer, so the pointer itself cannot be changed.
    *ptr2 = 20;               // Valid: Can modify the value of x through ptr2 because *ptr2 is not constant.

    // ptr3 = &MAX;           // Invalid: ptr3 is a constant pointer and cannot be changed.
    // *ptr3 = 30;            // Invalid: Cannot modify value pointed by ptr3 since it's a const int pointer to const data.

    std::cout << "x after ptr2 modification: " << x << std::endl;

    // Find which declarations are valid. If invalid, correct the declaration
    const int *ptr3 = &MAX;   // Valid: ptr3 is a pointer to a const int, and MAX is a const int.
    // int *ptr4 = &MAX;      // Invalid: Cannot assign the address of a const int (MAX) to a non-const pointer.
    const int *ptr4 = &MAX;   // Corrected: ptr4 should be a pointer to a const int.

    // References to const and non-const
    const int &r1 = ref_x1;   // Valid: r1 is a const reference to ref_x1 (non-const), this is allowed.
    // int &r2 = ref_x2;      // Invalid: Cannot assign a const reference (ref_x2) to a non-const reference.
    // Corrected:
    const int &r2 = ref_x2;   // r2 should be a const reference because ref_x2 is const.

    // Pointers to references
    // int *&p_ref1 = ptr1;   // Invalid: ptr1 is a pointer to a const int, cannot assign to a reference to a non-const pointer.
    const int *&p_ref1 = ptr1; // Corrected: p_ref1 should be a reference to a pointer to const int.
    
    // const int*&p_ref2 = ptr2; // Invalid: ptr2 is a constant pointer, cannot be assigned to a reference to const pointer.
    int *&p_ref2 = ptr2;      // Corrected: p_ref2 should be a reference to a non-const pointer.

    return 0;
}
