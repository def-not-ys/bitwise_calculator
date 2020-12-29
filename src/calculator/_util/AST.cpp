#include "AST.h"

namespace AST {
    Node::Node(): _x(0), _y(0), _ans(0) {}
    Node:: ~Node() {}            

    Expression::Expression(std::string exp): _expression(exp) {}
    Expression::~Expression() {
        // todo
    }
    void Expression::accept(Visitor* v) {
        v->visit(this);
    }

    Add::Add(Expression* left, Expression* right) : _left(left), _right(right) {}
    Add::~Add() {
        // todo
    }
    void Add::accept(Visitor* v) {
        v->visit(this);
    }


    Minus::Minus(Expression* left, Expression* right) : _left(left), _right(right) {}
    Minus::~Minus() {
        // todo
    }
    void Minus::accept(Visitor* v) {
        v->visit(this);
    }

    Multiply::Multiply(Expression* left, Expression* right) : _left(left), _right(right) {}
    Multiply::~Multiply() {
        // todo
    }
    void Multiply::accept(Visitor* v) {
        v->visit(this);
    }

    Divide::Divide(Expression* left, Expression* right) : _left(left), _right(right) {}
    Divide::~Divide() {
        // todo
    }
    void Divide::accept(Visitor* v) {
        v->visit(this);
    }
}