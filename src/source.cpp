#include <iostream>
#include <string>
#include <algorithm>

#include <ctype.h>

#include "./arithematics/arithematics.h"
#include "./ui/ui.h"


bool isValidMathExpression(std::string input) {
    return false;
}

int main() {

    std::cout << "this is a silly calculator" << std::endl;

    std::string input = "";
    int ans = 0;
    
    while (true) {
        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), 
                        [](unsigned char c) -> unsigned char {
                            return std::tolower(c);
                        });

        if (isValidMathExpression(input)) 
            std::cout << "ui.performCalculation(input, ans)" << std::endl;
        else if (input.compare("quit"))
            std::cout << "please enter valid math expression" << std::endl;
        else 
            break;
       
        std::cout << input << std::endl;
    }

    std::cout << "bye.." << std::endl;

    return 0;
}