#include "Parser.h"

namespace AST {
    void Parser::visit(Expression* node) {
        std::string expr = node->_expression;

        std::cout << "\n\nparsing Expression: " << expr << std::endl; //!!!

        int _loc = _findExpressionsLocation(expr);

        if (_loc < 0) {
            try {
                node->_x = std::stoi(expr);
                node->_ans = node->_x + node->_y;
            } catch (std::invalid_argument err) {
                throw ParseError("invalid argument");
            } catch (std::out_of_range err) {
                throw ParseError("out of range");
            }
        } else {
            Expression* l = new Expression(expr.substr(0,_loc));

            // std::cout << "\nbefore paring r expr: " << expr << "\n" << std::endl; // !!!

            Expression* r = new Expression(expr.substr(_loc + 1));
            char op = expr[_loc];

            std::cout << "expr: " << expr << " \nfirst: " << l->_expression << "\t second: " << r->_expression 
            << " \nop: " << op << std::endl; // !!!

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
                    break;
                default:
                    next_node = nullptr;
                    break;
            }
            node->_next = next_node;
            if (next_node)
                next_node->accept(this);
        }       
    }

    void Parser::visit(Add* node) {
        // todo
        std::cout << "parsing Add" << std::endl; // !!!
        node->_left->accept(this);
        node->_right->accept(this);
    }

    void Parser::visit(Minus* node) {
        // todo
        std::cout << "parsing Minus" << std::endl; // !!!
        node->_left->accept(this);
        node->_right->accept(this);
    }

    void Parser::visit(Multiply* node) {
        // todo
        std::cout << "parsing Multiply" << std::endl; // !!!
        node->_left->accept(this);
        node->_right->accept(this);
    }

    void Parser::visit(Divide* node) {
        // todo
        std::cout << "parsing Divide" << std::endl; // !!!
        node->_left->accept(this);
        node->_right->accept(this);
    }

    int Parser::test() {
        return 123; // !!!
    }

    int Parser::_findExpressionsLocation(std::string& str) {
        int _loc = 0, term = 0;

        if (str.length() == 0) 
            throw ParseError("empty string"); 
        
        if(str[0] == '(' && str[str.length()-1] == ')')
            str = str.substr(1,str.length()-2);

        if (str[0] == '(') 
            _loc = _findRightBracket(str); 
        else 
            _loc = _findFirstTerm(str);

        if (_loc > str.length()) {
			term = std::stoi(str);
			std::cout << "find base case exression: " << term << std::endl; // !!!
			_loc = -1;
		}
        return _loc;
    }

    int Parser::_findRightBracket(std::string &str) {
        // std::cout << "parsing term with ()" << std::endl; // !!!
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

        // std::cout << "after parsing "<< str <<  " with (): " << _loc << std::endl; // !!!
        return _loc;
    }

    int Parser::_findFirstTerm(std::string &str) {
        // std::cout << "parsing term without ()" << std::endl; // !!!
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
