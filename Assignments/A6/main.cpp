#include <iostream>
#include "functions.h"



int main() {
    std::string text = "tEst TeXt";
    
    std::string upperText = ToUpper(text);
    std::string lowerText = ToLower(text);

    std::cout << "String to Uppercase: " << upperText << std::endl;
    std::cout << "String to Lowercase: " << lowerText << std::endl;

    return 0;
}
