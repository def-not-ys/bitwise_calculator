#include "AST.h"

namespace AST {
    class Evaluator: public Visitor {
        public:

            ~Evaluator() {}

            int evaluate(const Expression* node) const {
                // node->accept(this);
                std::cout << "evaluating Expression" << std::endl;
                return 0;
            }

            int evaluate(const Add* node) const {
                // todo
                std::cout << "evaluating Add" << std::endl;
                return 0;
            }

            int evaluate(const Minus* node) const {
                // todo
                std::cout << "evaluating Minus" << std::endl;
                return 0;
            }

            int evaluate(const Multiply* node) const {
                // todo
                std::cout << "evaluating Multiply" << std::endl;
                return 0;
            }

            int evaluate(const Divide* node) const {
                // todo
                std::cout << "evaluating Divide" << std::endl;
                return 0;
            }

            int test() {
                return 321;
            }

            void parse(const Expression* node) const {};
            void parse(const Add* node) const {};
            void parse(const Minus* node) const {};
            void parse(const Multiply* node) const {};
            void parse(const Divide* node) const {};
    };
} 