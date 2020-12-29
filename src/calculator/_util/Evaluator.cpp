#include "Evaluator.h"

namespace AST {

    void Evaluator::visit(Expression* node) {
        // node->accept(this);
        std::cout << "evaluating Expression" << std::endl;
    }

    void Evaluator::visit(Add* node) {
        // todo
        std::cout << "evaluating Add" << std::endl;
    }

    void Evaluator::visit(Minus* node) {
        // todo
        std::cout << "evaluating Minus" << std::endl;
    }

    void Evaluator::visit(Multiply* node) {
        // todo
        std::cout << "evaluating Multiply" << std::endl;
    }

    void Evaluator::visit(Divide* node) {
        // todo
        std::cout << "evaluating Divide" << std::endl;
    }

    int Evaluator::test() {
        return 321;
    }
} 