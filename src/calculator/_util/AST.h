#ifndef AST_HEADER
#define AST_HEADER

#include <iostream>

namespace AST {

    struct Node; 
    struct Expression;
    struct Add;
    struct Minus;
    struct Multiply;
    struct Divide;

    struct Visitor {
        virtual void parse(const Expression* node) const = 0;
        virtual void parse(const Add* node) const = 0;
        virtual void parse(const Minus* node) const = 0;
        virtual void parse(const Multiply* node) const = 0;
        virtual void parse(const Divide* node) const = 0;

        virtual int evaluate(const Expression* node) const = 0;
        virtual int evaluate(const Add* node) const = 0;
        virtual int evaluate(const Minus* node) const = 0;
        virtual int evaluate(const Multiply* node) const = 0;
        virtual int evaluate(const Divide* node) const = 0;
    };
}

#endif