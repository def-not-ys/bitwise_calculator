#ifndef EVALUATOR_HEADER
#define EVALUATOR_HEADER

#include "AST.h"
#include "../../arithematics/arithematics.h"

namespace AST {
    class Evaluator: public Visitor {
        public:

            ~Evaluator();

            void visit(Expression* node);
            void visit(Add* node);
            void visit(Minus* node);
            void visit(Multiply* node);
            void visit(Divide* node);
    };
}

#endif