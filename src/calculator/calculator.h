#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "_util/AST.h"

std::string test();

class Calculator {
    
    public:
        Calculator();
        ~Calculator();
        Calculator(const Calculator& other) = delete;
        Calculator& operator= (const Calculator& other) = delete;

        int processInput(const std::string& input); // throws ParseError if input is invalid. returns result otherwise

    private:
        // bool _isValidMathExpression(std::string& input); // regex
        void _format(std::string& str); // removing spaces in the input string 
        int _calculate();
        void _clear();

        int _ans;
        AST::Node* _node;
        
};

#endif

