#include "AST.cpp"

namespace AST {

    template<typename T>
    struct Parser: public Visitor<void> {
        void visit(Expression* node) const {
            node.accept(this);
        }

        void visit(Add* node) const {
            // todo
        }

        void visit(Minus* node) const {
            // todo
        }

        void visit(Multiply* node) const {
            // todo
        }

        void visit(Divide* node) const {
            // todo
        }
    };
}
