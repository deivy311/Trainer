#include <iostream>

int main() {
    int x = 10;          // Regular integer variable
    int y = 20;          // Another integer for testing pointer reassignment

    // Constant pointer to an integer: the value pointed to by ptr1 cannot be modified via ptr1
    const int *ptr1 = &x;
    // Constant pointer: ptr2 cannot point to another variable, but the pointee (x) can be modified
    int *const ptr2 = &x;
    // A fully constant pointer: neither the pointer nor the pointee can be modified
    const int *const ptr3 = &x;

    std::cout << "Initial values:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << std::endl;
    std::cout << "*ptr2 = " << *ptr2 << std::endl;
    std::cout << "*ptr3 = " << *ptr3 << std::endl;

    // Attempt to modify the pointee value via ptr1
    // *ptr1 = 30; // This will cause a compilation error (ptr1 points to const int)

    // Modify the pointee value via ptr2
    *ptr2 = 30; // This is allowed since ptr2 points to a non-const int
    std::cout << "\nAfter modifying *ptr2:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << std::endl; // Reflects the change in x
    std::cout << "*ptr2 = " << *ptr2 << std::endl;
    std::cout << "*ptr3 = " << *ptr3 << std::endl;

    // Try to modify the pointer itself (make ptr1 point to y)
    ptr1 = &y; // This is allowed because ptr1 is not a constant pointer (the pointer itself can change)
    std::cout << "\nAfter changing ptr1 to point to y:" << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << std::endl;

    // Try to modify the pointer ptr2 itself (make ptr2 point to y)
    // ptr2 = &y; // This will cause a compilation error (ptr2 is a constant pointer)

    // Try to modify the pointer ptr3 itself or the pointee value
    // *ptr3 = 40;  // Compilation error: ptr3 points to a const int
    // ptr3 = &y;   // Compilation error: ptr3 is a const pointer

    return 0;
}
