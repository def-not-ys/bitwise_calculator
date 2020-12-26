#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

#include "_util/AST.cpp";

std::string test();

class Calculator {
    public:
        struct ParseError {};

    public:
        Calculator();
        ~Calculator();
        Calculator(const Calculator& other) = delete;
        Calculator& operator= (const Calculator& other) = delete;

        int processInput(const std::string& input); // throws ParseError if input is invalid. returns result otherwise

    private:
        bool _isValidMathExpression(std::string& input); // regex
        int _calculate();

        int _ans;
        AST::Node _node;
        
};

#endif

