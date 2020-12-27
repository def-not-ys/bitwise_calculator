#include "Evaluator.h"

namespace AST {

    void Evaluator::visit(Expression* node) const {
        // node->accept(this);
        std::cout << "evaluating Expression" << std::endl;
    }

    void Evaluator::visit(Add* node) const {
        // todo
        std::cout << "evaluating Add" << std::endl;
    }

    void Evaluator::visit(Minus* node) const {
        // todo
        std::cout << "evaluating Minus" << std::endl;
    }

    void Evaluator::visit(Multiply* node) const {
        // todo
        std::cout << "evaluating Multiply" << std::endl;
    }

    void Evaluator::visit(Divide* node) const {
        // todo
        std::cout << "evaluating Divide" << std::endl;
    }

    int Evaluator::test() {
        return 321;
    }
} 