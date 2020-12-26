#include "AST.cpp"

namespace AST {

    template<typename T>
    class Evaluator: public Visitor<int> {
        public:
            int visit(Expression* node) const {
                // todo 
            }

            int visit(Add* node) const {
                // todo 
            }

            int visit(Minus* node) const {
                // todo 
            }

            int visit(Multiply* node) const {
                // todo 
            }

            int visit(Divide* node) const {
                // todo 
            }
    };
} 