#include <iostream>
#include "functions.h"

int main() {
    std::string source = "My name is Latifa Alkaabi!";
    // std::string search_string = "Latifa";
    std::string search_string = "latifa";

    size_t insensitive = Find(source, search_string, Case::INSENSITIVE);
    size_t sensitive = Find(source, search_string, Case::SENSITIVE);

    if (insensitive != std::string::npos) {
        std::cout << "Match (insensitive) at position: " << insensitive << std::endl;
    } else {
        std::cout << "No match found (insensitive)." << std::endl;
    }

    if (sensitive != std::string::npos) {
        std::cout << "Match (sensitive) at position: " << sensitive << std::endl;
    } else {
        std::cout << "No match found (sensitive)." << std::endl;
    }


    return 0;
}
