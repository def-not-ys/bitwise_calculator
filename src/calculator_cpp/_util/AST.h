#ifndef AST_HEADER
#define AST_HEADER

#define DEBUG_ON 0

#include <iostream> 
#include <string>

#include "ASTError.cpp"

namespace AST {

    struct Visitor;

    struct Node {
        Node();
        Node(std::string exp);
        virtual ~Node() = 0;
        virtual void accept(Visitor* v) = 0;         

        int _x, _y, _ans;
        std::string _expression;
    };

    struct Expression: public Node {
        Expression(std::string exp);
        ~Expression();
        void accept(Visitor* v);

        Node* _next;
    };

    struct Add: public Node {
        Add(Expression* left, Expression* right);
        ~Add();
        void accept(Visitor* v);

        Expression* _left;
        Expression* _right;
    };

    struct Minus: public Node {
        Minus(Expression* left, Expression* right);
        ~Minus();
        void accept(Visitor* v);

        Expression* _left;
        Expression* _right;
    };

    struct Multiply: public Node {
        Multiply(Expression* left, Expression* right);
        ~Multiply();
        void accept(Visitor* v);

        Expression* _left;
        Expression* _right;
    };

    struct Divide: public Node {
        Divide(Expression* left, Expression* right);
        ~Divide();
        void accept(Visitor* v);

        Expression* _left;
        Expression* _right;
    };

    struct Visitor {
        virtual ~Visitor() = 0;
        virtual void visit(Expression* node) = 0;
        virtual void visit(Add* node) = 0;
        virtual void visit(Minus* node) = 0;
        virtual void visit(Multiply* node) = 0;
        virtual void visit(Divide* node) = 0;
    };

    inline Visitor::~Visitor() { }

}

#endif