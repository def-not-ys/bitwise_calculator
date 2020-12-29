#include "Parser.h"

namespace AST {
    void Parser::visit(Expression* node) {
        std::string expr = node->_expression;
        // std::cout << "parsing Expression: " << expr << std::endl;
        int _loc = _findExpressionsLocation(expr);

        if (_loc < 0) {
            node->_x = std::stoi(expr);
            node->_ans = node->_x + node->_y;
        } else {
            Expression* l = new Expression(expr.substr(0,_loc));
            Expression* r = new Expression(expr.substr(_loc + 1));
            char op = expr[_loc];

            std::cout << "expr: " << expr << " \nfirst: " << l->_expression << " second: " << r->_expression 
            << " \nloc: " << _loc << " \nop: " << op << std::endl;

            Node* next_node;
            
            switch (op) {
                case '+':
                    next_node = new Add(l, r);
                    break;
                case '-':
                    next_node = new Minus(l, r);
                    break;
                case '*':
                    next_node = new Multiply(l, r);
                    break;
                case '/':
                    next_node = new Divide(l, r);
            }
            node->_next = next_node;

            next_node->accept(this);
        }       
    }

    void Parser::visit(Add* node) {
        // todo
        std::cout << "parsing Add" << std::endl;
    }

    void Parser::visit(Minus* node) {
        // todo
        std::cout << "parsing Minus" << std::endl;
    }

    void Parser::visit(Multiply* node) {
        // todo
        std::cout << "parsing Multiply" << std::endl;
    }

    void Parser::visit(Divide* node) {
        // todo
        std::cout << "parsing Divide" << std::endl;
    }

    int Parser::test() {
        return 123;
    }

    int Parser::_findExpressionsLocation(std::string& str) {
        int _loc = 0, term = 0;

        if (str.length() == 0) 
            throw ParseError("empty string");
        
        if (str[0] == '(') 
            _loc = _findRightBracket(str); 
        else 
            _loc = _findFirstTerm(str);

        if (_loc > str.length()) {
			term = std::stoi(str);
			std::cout << "find base case exression: " << term << std::endl;
			_loc = -1;
		}
        return _loc;
    }

    int Parser::_findRightBracket(std::string &str) {
        std::cout << "parsing term with ()" << std::endl;
        str.erase(0, 1);
        int _rb = 1, _loc = 0;
        while (_rb && _loc++ <= str.length()) {
            if (str[_loc] == ')' ) 
                _rb--;
            else if (str[_loc] == '(')
                _rb++;
        }
        if (_rb != 0) 
            throw ParseError("unbalanced brackets");
        str.erase(_loc, 1);
        return _loc;
    }

    int Parser::_findFirstTerm(std::string &str) {
        std::cout << "parsing term without ()" << std::endl;
		int _loc = 0;
		while (_loc++ <= str.length()) {
			if (_isOperator(str[_loc])) 
				break;
		}
        return _loc; 
    }

    bool Parser::_isOperator(const char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

}
