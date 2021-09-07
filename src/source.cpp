#include <iostream>
#include <string>
#include <algorithm>

#include <ctype.h>

#include "./calculator_cpp/calculator.h"

int main() {

    std::cout << "this is a silly calculator" << std::endl;

    std::string input = "";
    Calculator calculator;

    while (true) {
        std::cin >> input; // remove all spaces
        std::transform(input.begin(), input.end(), input.begin(),
                        [](unsigned char c) -> unsigned char {
                            return std::tolower(c);
                        });
        if (input.compare("quit")) {
            try {
                int result = 0;
                result = calculator.processInput(input);
                std::cout << input << " = " << result << std::endl;
            } catch (AST::ASTError err) {
                std::cout << err.getMessage() << std::endl;
            }
        } else
            break;
    }

    std::cout << "bye.." << std::endl;

    return 0;
}