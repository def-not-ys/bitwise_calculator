// #include "AST.h"

#include "Parser.cpp"
#include "Evaluator.cpp"

namespace AST {

    struct Node {
        Node() {}
        virtual ~Node() {};
        virtual void accept(const Visitor* v) const = 0;         
        // virtual void accept(const Parser* v) const = 0;
        // virtual void accept(const Evaluator* v) const = 0;

        int _x, _y, _ans;
    };

    struct Expression: public Node {
        Expression() {}
        ~Expression() {
            // todo
        };
        void accept(const Visitor* v) const {
            v->parse(this);
            v->evaluate(this);
        }
    };

    struct Add: public Node {
        Add() {}
        ~Add() {
            // todo
        };
        void accept(const Visitor* v) const {
            // stub
        }
    };

    struct Minus: public Node {
        Minus() {}
        ~Minus() {
            // todo
        };
        void accept(const Visitor* v) const {
            // stub
        }
    };

    struct Multiply: public Node {
        Multiply() {}
        ~Multiply() {
            // todo
        };
        void accept(const Visitor* v) const {
            // stub
        }
    };

    struct Divide: public Node {
        Divide() {}
        ~Divide() {
            // todo
        };
        void accept(const Visitor* v) const {
            // stub
        }
    };
}