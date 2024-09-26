#include <iostream>

int main() {
    /*Part 1************************************************************************/
    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x;
    const int &ref_x2 = x ;

    std::cout << "***Part_1 " << std::endl;
    std::cout << "Before modification:" << std::endl;
    std::cout << "x = " << x << "\tref_x1 = " << ref_x1 << "\tref_x2 = " << ref_x2 << std::endl;

    ref_x1 = 2;
    // ref_x2 = 20;
    std::cout << "After modification (ref_x1 = " << ref_x1 <<"):" << std::endl; 
    std::cout << "x = " << x << "\tref_x1 = " << ref_x1 << "\tref_x2 = " << ref_x2 << std::endl;

    
    /*Part 2************************************************************************/
    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    std::cout << "***Part_2 " << std::endl;
    const int *ptr1 = &x ;
    int *const ptr2 = &x ;
    const int * const ptr3 = &x ;
    std::cout << "Before modification (x = " << x <<"):" << std::endl; 
    std::cout << "*ptr1 = " << *ptr1 << "\t*ptr2 = " << *ptr2 << "\t*ptr3 = " << *ptr3 << std::endl;

    x=9;
    // ptr1 = 10;  // assignment of read-only
    std::cout << "After modification (x = " << x <<"):" << std::endl; 
    std::cout << "*ptr1 = " << *ptr1 << "\t*ptr2 = " << *ptr2 << "\t*ptr3 = " << *ptr3 << std::endl;
    
    // *ptr1 = 20;  // assignment of read-only
    std::cout << "After modification (*ptr1 = " << *ptr1 <<"):" << std::endl; 
    std::cout << "x = " << x << "\tptr1 = " << ptr1 << "\tptr2 = " << *ptr2 << "\t*ptr3 = " << *ptr3 << std::endl;

    *ptr2 = 30;  // assignment of read-only
    std::cout << "After modification (*ptr2 = " << *ptr2 <<"):" << std::endl; 
    std::cout << "x = " << x << "\t*ptr1 = " << *ptr1 << "\t*ptr3 = " << *ptr3 << std::endl;
    std::cout <<".: const pointer to a non-const int"<< std::endl;

    // *ptr3 = 50;  // assignment of read-only
    // std::cout << "After modification (*ptr3 = " << *ptr3 <<"):" << std::endl; 
    // std::cout << "x = " << x << "\t*ptr2 = " << *ptr2 << "\t*ptr3 = " << *ptr3 << std::endl;

    /*Part 3************************************************************************/
    //Find which declarations are valid. If invalid, correct the declaration
    std::cout << "***Part_3 " << std::endl;
    /*1*/
    const int *ptr5 = &MAX ;
    std::cout << "1. Before modification (Pointer to const int):" << std::endl; 
    std::cout << "\tvalid declaration: const int *ptr5 = &MAX , where *ptr5 = " << *ptr5 << std::endl; 
    
    /*2*/
    // int *ptr4 = &MAX ;
    std::cout << "2. Before modification (assign a const int to a to non-const pointer):" << std::endl; 
    std::cout << "\tInvalid declaration: int *ptr4 = &MAX, where &MAX is const" << std::endl; 
    const int *ptr4 = &MAX;
    std::cout << "\tAfter modifecation: const int *ptr4 = &MAX, where *ptr4 = " << *ptr4 << std::endl; 

    /*3*/ 
    const int &r1 = ref_x1 ;
    std::cout << "3. Before modification (Const ref. to non-const ref.):" << std::endl; 
    std::cout << "\tValid declaration: const int &r1 = ref_x1, where ref_x1 is non-const ref."<< std::endl; 

    /*4*/
    // int &r2 = ref_x2 ;
    std::cout << "4. Before modification (assign a const ref. to non-const ref.):" << std::endl; 
    std::cout << "\tInvalid declaration: int &r2 = ref_x2, where ref_x2 is constant" << r1 << std::endl; 
    const int &r2 = ref_x2;  
    std::cout << "\tAfter modifecation: const int &r2 = ref_x2, where r2 = " << r2 << std::endl; 
    
    /*5*/
    // int *&p_ref1 = ptr1;  
    std::cout << "5. Before modification (non-const reference to a pointer to const):" << std::endl; 
    std::cout << "\tInvalid declaration: int *&p_ref1 = ptr1, where ptr1 is const int*" << r1 << std::endl; 
    const int *&p_ref1 = ptr1;  
    std::cout << "\tAfter modifecation: const int *&p_ref1 = ptr1, where *&p_ref1 = " << *&p_ref1 << std::endl; 

    /*6*/
    // const int *&p_ref2 = ptr2;  
    std::cout << "5. Before modification (assign non-const pointer to int):" << std::endl; 
    std::cout << "\tInvalid declaration: const int *&p_ref2 = ptr2, where ptr2 int *const" << r1 << std::endl; 
    int *const &p_ref2 = ptr2;  
    std::cout << "\tAfter modifecation: int *const &p_ref2 = ptr2, where  &p_ref2 is int *const" << std::endl; 

}