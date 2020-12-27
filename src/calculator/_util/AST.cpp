#include "AST.h"

namespace AST {
    Node::Node() {
        // set: int _x, _y, _ans;
    }
    Node:: ~Node() {}            

    Expression::Expression() {}
    Expression::~Expression() {
        // todo
    }
    void Expression::accept(const Visitor* v) {
        v->visit(this);
    }

    Add::Add() {}
    Add::~Add() {
        // todo
    }
    void Add::accept(const Visitor* v) {
        // stub
    }


    Minus::Minus() {}
    Minus::~Minus() {
        // todo
    }
    void Minus::accept(const Visitor* v) {
        // stub
    }

    Multiply::Multiply() {}
    Multiply::~Multiply() {
        // todo
    }
    void Multiply::accept(const Visitor* v) {
        // stub
    }

    Divide::Divide() {}
    Divide::~Divide() {
        // todo
    }
    void Divide::accept(const Visitor* v) {
        // stub
    }
}