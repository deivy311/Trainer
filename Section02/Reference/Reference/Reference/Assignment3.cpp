#include <iostream>

int main() {
    // Initial variable declarations
    int x = 5;
    const int MAX = 12;

    // References
    int &ref_x1 = x;          // A reference to a non-const int, this is modifiable.
    const int &ref_x2 = x;    // A const reference, this cannot modify the value of x.

    ref_x1 = 10;              // Valid
    // ref_x2 = 15;           // Invalid: Cannot modify x through ref_x2 because it's const.

    // Pointers
    const int *ptr1 = &x;     // ptr1 can point to another address, but the value *ptr1 cannot be changed.
    int *const ptr2 = &x;     // ptr2 is a constant pointer to int, meaning the pointer itself cannot change, but *ptr2 can.
    const int *const ptr3 = &x;  // ptr3 is a constant pointer to a constant int.

    // Modifying pointers and pointees
    ptr1 = &MAX;              // Valid: ptr1 can point to another const int.
    // *ptr1 = 20;            // Invalid: Cannot modify value pointed by ptr1.

    *ptr2 = 20;               // Valid: Can modify the value of x through ptr2 because *ptr2 is not constant.
    // ptr2 = &MAX;           // Invalid: Cannot change the pointer itself.

    // Pointer references
    const int *&p_ref1 = ptr1;   // p_ref1 is a reference to a pointer to const int.
    int *const &p_ref2 = ptr2;   // p_ref2 is a reference to a constant pointer.

    return 0;
}
