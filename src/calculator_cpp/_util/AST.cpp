#include "AST.h"

namespace AST {
    Node::Node(): _x(0), _y(0), _ans(0) {}
    Node:: ~Node() {}            

    Expression::Expression(std::string exp): _expression(exp), _next(0) {}
    Expression::~Expression() {
        if (_next) delete _next;
    }
    void Expression::accept(Visitor* v) {
        v->visit(this);
    }

    Add::Add(Expression* left, Expression* right) : _left(left), _right(right) {}
    Add::~Add() {
        if (_left) delete _left;
        if (_right) delete _right;
    }
    void Add::accept(Visitor* v) {
        v->visit(this);
    }


    Minus::Minus(Expression* left, Expression* right) : _left(left), _right(right) {}
    Minus::~Minus() {
        if (_left) delete _left;
        if (_right) delete _right;   
    }
    void Minus::accept(Visitor* v) {
        v->visit(this);
    }

    Multiply::Multiply(Expression* left, Expression* right) : _left(left), _right(right) {}
    Multiply::~Multiply() {
        if (_left) delete _left;
        if (_right) delete _right;   
    }
    void Multiply::accept(Visitor* v) {
        v->visit(this);
    }

    Divide::Divide(Expression* left, Expression* right) : _left(left), _right(right) {}
    Divide::~Divide() {
        if (_left) delete _left;
        if (_right) delete _right;    
    }
    void Divide::accept(Visitor* v) {
        v->visit(this);
    }
}