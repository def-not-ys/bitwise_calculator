#ifndef PARSER_HEADER
#define PAER_HEADER

#include "AST.h"

namespace AST {
    struct Parser: public Visitor {
        void visit(Expression* node) const;
        void visit(Add* node) const;
        void visit(Minus* node) const;
        void visit(Multiply* node) const;
        void visit(Divide* node) const;

        int test();
    };
}

#endif