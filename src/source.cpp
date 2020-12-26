#include <iostream>
#include <string>
#include <algorithm>

#include <ctype.h>

#include "./calculator/calculator.h"

int main() {

    std::cout << "this is a silly calculator" << std::endl;

    std::string input = "";
    Calculator calculator;
    
    while (true) {
        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), 
                        [](unsigned char c) -> unsigned char {
                            return std::tolower(c);
                        });

        if (input.compare("quit"))
            std::cout << "please enter valid math expression" << std::endl;
        else 
            break;
       
        std::cout << input << std::endl;
    }

    std::cout << "bye.." << std::endl;

    return 0;
}