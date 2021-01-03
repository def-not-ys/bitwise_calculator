#include "Evaluator.h"

namespace AST {

    void Evaluator::visit(Expression* node) {
        std::cout << "evaluating Expression " << node->_expression << std::endl; //!!!
        
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
        // std::cout << "\n\nevaluated base expression: " << node->_ans << "\n\n" << std::endl;              
    }

    void Evaluator::visit(Add* node) {
        std::cout << "evaluating Add:: " << std::endl;  // !!!

        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = addition_integer(node->_left->_ans, node->_right->_ans);

        std::cout << "to: " << node->_ans << std::endl;
    }

    void Evaluator::visit(Minus* node) {

        std::cout << "evaluating Minus:: " << std::endl; //!!!
        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = subtraction_integer(node->_left->_ans, node->_right->_ans);
        std::cout << "to: " << node->_ans << std::endl;
    }

    void Evaluator::visit(Multiply* node) {
        // todo
        std::cout << "evaluating Multiply:: " << std::endl;

        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = multiplication_integer_russian_peasant(node->_left->_ans, node->_right->_ans);

        std::cout << "to: " << node->_ans << std::endl;
    }

    void Evaluator::visit(Divide* node) {
        // todo
        std::cout << "evaluating Divide:: " << std::endl;

        node->_left->accept(this);
        node->_right->accept(this);

        node->_ans = division_integer_restoring(node->_left->_ans, node->_right->_ans);

        std::cout << "to: " << node->_ans << std::endl;
    }
} 