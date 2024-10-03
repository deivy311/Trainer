#include <iostream>
#include <string>
#include "functions.h"  

int main() {
    std::string source = "My name is Latifa Alkaabi! it is such a nice NAME";
    std::string search_string = "NAME";


    // case-insensitive search
    size_t insensitive = Find(source, search_string, Case::INSENSITIVE);

    if (insensitive != std::string::npos) {
        std::cout << "Match (insensitive) at position: " << insensitive << std::endl;
    } else {
        std::cout << "No match found (insensitive)." << std::endl;
    }

    // case-sensitive search
    size_t sensitive = Find(source, search_string, Case::SENSITIVE);

    if (sensitive != std::string::npos) {
        std::cout << "Match (sensitive) at position: " << sensitive << std::endl;
    } else {
        std::cout << "No match found (sensitive)." << std::endl;
    }

    return 0;
}

