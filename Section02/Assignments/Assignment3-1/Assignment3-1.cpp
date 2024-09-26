#include <iostream>

int main() {
    int x = 5;                  // Regular integer variable
    const int MAX = 12;          // Constant integer
    int &ref_x1 = x;             // Non-const reference to x
    const int &ref_x2 = x;       // Const reference to x

    // Try to modify x, ref_x1, and ref_x2
    std::cout << "Initial values: " << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "ref_x1 = " << ref_x1 << std::endl;
    std::cout << "ref_x2 = " << ref_x2 << std::endl;

    // Modify x and ref_x1
    x = 10;                      // Modifying x
    ref_x1 = 20;                 // Modifying x through ref_x1
    std::cout << "\nAfter modifying x and ref_x1:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "ref_x1 = " << ref_x1 << std::endl;
    std::cout << "ref_x2 = " << ref_x2 << std::endl;

    // Uncomment the line below and try to modify ref_x2
    //ref_x2 = 30;               // This will give a compilation error

    return 0;
}
