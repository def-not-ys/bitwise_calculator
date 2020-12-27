#include "AST.h"

namespace AST {

    struct Parser: public Visitor {

        void parse(const Expression* node) const {
            // node->accept(this);
            std::cout << "parsing Expression" << std::endl;
        }

        void parse(const Add* node) const {
            // todo
            std::cout << "parsing Add" << std::endl;
        }

        void parse(const Minus* node) const {
            // todo
            std::cout << "parsing Minus" << std::endl;
        }

        void parse(const Multiply* node) const {
            // todo
            std::cout << "parsing Multiply" << std::endl;
        }

        void parse(const Divide* node) const {
            // todo
            std::cout << "parsing Divide" << std::endl;
        }

        int test() {
            return 123;
        }

        int evaluate(const Expression* node) const { return 0; };
        int evaluate(const Add* node) const { return 0; };
        int evaluate(const Minus* node) const { return 0; };
        int evaluate(const Multiply* node) const { return 0; };
        int evaluate(const Divide* node) const { return 0; };
    };
}
