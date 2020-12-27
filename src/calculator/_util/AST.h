#ifndef AST_HEADER
#define AST_HEADER

#include <iostream>

namespace AST {
    
    struct Visitor;

    struct Node {
        Node();
        virtual ~Node();
        virtual void accept(const Visitor* v) = 0;         

        int _x, _y, _ans;
    };

    struct Expression: public Node {
        Expression();
        ~Expression();
        void accept(const Visitor* v);
    };

    struct Add: public Node {
        Add();
        ~Add();
        void accept(const Visitor* v);
    };

    struct Minus: public Node {
        Minus();
        ~Minus();
        void accept(const Visitor* v);
    };

    struct Multiply: public Node {
        Multiply();
        ~Multiply();
        void accept(const Visitor* v);
    };

    struct Divide: public Node {
        Divide();
        ~Divide();
        void accept(const Visitor* v);
    };

    struct Visitor {
        virtual void visit(Expression* node) const = 0;
        virtual void visit(Add* node) const = 0;
        virtual void visit(Minus* node) const = 0;
        virtual void visit(Multiply* node) const = 0;
        virtual void visit(Divide* node) const = 0;
    };
}

#endif