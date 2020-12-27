#include "Parser.h"

namespace AST {
    void Parser::visit(Expression* node) const {
        // node->accept(this);
        std::cout << "parsing Expression" << std::endl;
    }

    void Parser::visit(Add* node) const {
        // todo
        std::cout << "parsing Add" << std::endl;
    }

    void Parser::visit(Minus* node) const {
        // todo
        std::cout << "parsing Minus" << std::endl;
    }

    void Parser::visit(Multiply* node) const {
        // todo
        std::cout << "parsing Multiply" << std::endl;
    }

    void Parser::visit(Divide* node) const {
        // todo
        std::cout << "parsing Divide" << std::endl;
    }

    int Parser::test() {
        return 123;
    }

}
