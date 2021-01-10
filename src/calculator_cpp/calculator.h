#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "_util/Parser.h"
#include "_util/Evaluator.h"

class Calculator {
    
    public:
        Calculator();
        ~Calculator();
        Calculator(const Calculator& other) = delete;
        Calculator& operator= (const Calculator& other) = delete;

        int processInput(const std::string& input); // throws ASTError if input is invalid. returns result otherwise

    private:
        void _format(std::string& str); // removing spaces in the input string 
        void _parse();
        void _evaluate();
        void _clear();

        int _ans;
        AST::Node* _node;
        AST::Parser* _parser;
        AST::Evaluator* _evaluator;
        
};

#endif

