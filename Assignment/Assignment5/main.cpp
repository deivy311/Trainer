#include <iostream>
#include "functions.hpp"

int main() {
    std::string text = "Hello, World! Welcome to the C++ programming world.";
    
    // Case-sensitive search
    size_t pos1 = Find(text, "World", Case::SENSITIVE);
    std::cout << "Case-sensitive search for 'World': " << pos1 << std::endl;

    // Case-insensitive search
    size_t pos2 = Find(text, "world", Case::INSENSITIVE);
    std::cout << "Case-insensitive search for 'world': " << pos2 << std::endl;

    // Search with offset
    size_t pos3 = Find(text, "o", Case::INSENSITIVE, 5);
    std::cout << "Case-insensitive search for 'o' starting at offset 5: " << pos3 << std::endl;

    return 0;
}
