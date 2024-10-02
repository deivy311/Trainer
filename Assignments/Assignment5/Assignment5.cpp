#include <iostream>
#include "search_util.h"

int main() {
    std::string source = "Hello World";
    std::string search_string = "world";

    // Case-insensitive search
    size_t pos = Find(source, search_string, Case::INSENSITIVE);
    if (pos != std::string::npos) {
        std::cout << "Found at position (case-insensitive): " << pos << std::endl;
    } else {
        std::cout << "Not found (case-insensitive)" << std::endl;
    }

    // Case-sensitive search
    pos = Find(source, search_string, Case::SENSITIVE);
    if (pos != std::string::npos) {
        std::cout << "Found at position (case-sensitive): " << pos << std::endl;
    } else {
        std::cout << "Not found (case-sensitive)" << std::endl;
    }

    return 0;
}
