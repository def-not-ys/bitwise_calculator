#include "Evaluator.h"

namespace AST {

    Evaluator::~Evaluator() {}

    void Evaluator::visit(Expression* node) {      
        if (node->_next) {
            node->_next->accept(this);
            node->_ans = node->_next->_ans;
        } else {
            std::string expr = node->_expression;
            try {
                node->_ans = std::stoi(expr);
            } catch (std::invalid_argument err) {
                throw ASTError("EvaluatorError::invalid argument");
            } catch (std::out_of_range err) {
                throw ASTError("EvaluatorError::out of range");
            }            
        }         
    }

    void Evaluator::visit(Add* node) {
        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = addition_integer(node->_left->_ans, node->_right->_ans);
    }

    void Evaluator::visit(Minus* node) {
        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = subtraction_integer(node->_left->_ans, node->_right->_ans);
    }

    void Evaluator::visit(Multiply* node) {

        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = multiplication_integer_russian_peasant(node->_left->_ans, node->_right->_ans);
    }

    void Evaluator::visit(Divide* node) {
        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = division_integer_restoring(node->_left->_ans, node->_right->_ans);
    }
} 