#ifndef EVALUATOR_HEADER
#define EVALUATOR_HEADER

#include "AST.h"

namespace AST {
    class Evaluator: public Visitor {
        public:
            void visit(Expression* node) const;
            void visit(Add* node) const;
            void visit(Minus* node) const;
            void visit(Multiply* node) const;
            void visit(Divide* node) const;
        // protected:
            int test();
    };
}

#endif