#ifndef AST_HEADER
#define AST_HEADER

#include <iostream> // debug only 
#include <string>

#include "ASTError.cpp"

namespace AST {

    struct Visitor;

    struct Node {
        Node();
        virtual ~Node();
        virtual void accept(Visitor* v) = 0;         

        int _x = 0, _y = 0, _ans = 0;
    };

    struct Expression: public Node {
        Expression(std::string exp);
        ~Expression();
        void accept(Visitor* v);

        std::string _expression;
        Node* _next = nullptr;
    };

    struct Add: public Node {
        Add(Expression* left, Expression* right);
        ~Add();
        void accept(Visitor* v);

        Expression* _left = nullptr;
        Expression* _right = nullptr;
    };

    struct Minus: public Node {
        Minus(Expression* left, Expression* right);
        ~Minus();
        void accept(Visitor* v);

        Expression* _left = nullptr;
        Expression* _right = nullptr;
    };

    struct Multiply: public Node {
        Multiply(Expression* left, Expression* right);
        ~Multiply();
        void accept(Visitor* v);

        Expression* _left = nullptr;
        Expression* _right = nullptr;
    };

    struct Divide: public Node {
        Divide(Expression* left, Expression* right);
        ~Divide();
        void accept(Visitor* v);

        Expression* _left = nullptr;
        Expression* _right = nullptr;
    };

    struct Visitor {
        virtual void visit(Expression* node) = 0;
        virtual void visit(Add* node) = 0;
        virtual void visit(Minus* node) = 0;
        virtual void visit(Multiply* node) = 0;
        virtual void visit(Divide* node) = 0;
    };
}

#endif