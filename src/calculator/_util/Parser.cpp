#include "Parser.h"

namespace AST {
    void Parser::visit(Expression* node) {
        std::string expr = node->_expression;

        std::cout << "\n\nparsing Expression: " << expr << std::endl; //!!!

        int _loc = _findExpressionsLocation(expr);

        Node* next_node = nullptr;

        if (_loc < 0) {
            try {
                node->_x = std::stoi(expr);
                node->_ans = node->_x + node->_y;
            } catch (std::invalid_argument err) {
                throw ParseError("invalid argument");
            } catch (std::out_of_range err) {
                throw ParseError("out of range");
            }
        } 
        else if (_loc == expr.length()-1) {
            std::cout << "nested expression" << std::endl;
            next_node = new Expression(expr.substr(0, expr.length()));
        }         
        else {
            Expression* l = new Expression(expr.substr(0,_loc + 1));
            Expression* r = new Expression(expr.substr(_loc + 2));
            char op = expr[_loc+1];

            std::cout << "expr: " << expr << " \nfirst: " << l->_expression << "\t second: " << r->_expression 
            << " \nop: " << op << std::endl; // !!!           
            
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
            
        } 
        node->_next = next_node;
        if (next_node)
            next_node->accept(this);      
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

    // prioritize operation by inserting brackets 
    void Parser::prioritize(std::string& str) {
        int i = 0;
        if (str.length() < 1 || _isOperator(str[0]))
            str = "0" + str;
        _checkImplicitMultiply(str);
        while (i < str.length()) {
            if (str[i] == '*' || str[i] == '/') {
                    _prioritize_left(str, i);
                    i++;
                    _prioritize_right(str, i);
            }
            i++;
        }

        std::cout << "prioritized:: " << str << std::endl;
    }

    int Parser::test() {
        return 123; // !!!
    }

    int Parser::_findExpressionsLocation(std::string& str) {
        int _loc = 0, term = 0;

        if (str.length() == 0) 
            throw ParseError("empty string"); 

        if (str[0] == '(') {
            str.erase(0, 1); 
            _loc = _findRightBracket(str, 0, str.length()); 
            if (_loc >= str.length()) _loc = str.length() - 1; 
            str.erase(_loc, 1);
            _loc--;
        }
        else 
            _loc = _findTermEnd(str, 0);

        if (_loc > str.length()-1) {
            try {
                term = std::stoi(str);
                _loc = -1;
            } catch(std::invalid_argument) {
                _loc = str.length();
            }		
		}
        return _loc;
    }

    // retrusn the position of the matching right bracket 
    int Parser::_findRightBracket(const std::string &str, int sub_start, int sub_end) {
        std::string s = str.substr(sub_start, sub_end);
		int _rb = 1, _loc = 0;
		while (_rb && _loc < s.length()) {
            if (s[_loc] == ')' ) 
                    _rb--;
            else if (s[_loc] == '(')
                    _rb++;
            _loc++;
		}
        if (_rb != 0) 
            throw ParseError("unbalanced brackets");
        return _loc+sub_start-1;
    }

    // retrusn the position of the matching right bracket 
    int Parser::_findLeftBracket(const std::string &str, int sub_start, int sub_end) {
        std::string s = str.substr(sub_start, sub_end);
        int _lb = 1, _loc = sub_end-1;
        while (_lb && _loc >= 0) {
            if (str[_loc] == '(' ) 
                _lb--;
            else if (str[_loc] == ')')
                _lb++;

            _loc--;
        }
        if (_lb != 0) 
            throw ParseError("unbalanced brackets");
        return _loc+1;
    }

    int Parser::_findTermStart(std::string &str, int _loc) {
		while (_loc-- > 0) {
			if (_isOperator(str[_loc])) 
				break;
		}
        return _loc+1; 
    }

    int Parser::_findTermEnd(std::string &str, int _loc) {
		while (_loc++ < str.length()) {
			if (_isOperator(str[_loc])) 
				break;
		}
        return _loc-1; 
    }

    // insert implicit *
    void Parser::_checkImplicitMultiply(std::string& str) {
        int i = 1;
        while (i < str.length()-1) {
            if (str[i] == '(') {
                if (_isNumber(str[i-1]))
                    str.insert(i, "*");
            }	else if (str[i] == ')') {
                if (str[i+1] > 47 && str[i+1] < 58)
                    str.insert(i+1, "*");
            }
            i++;
        }
    }   

    // inserts left bracket for the prioritized expression
    void Parser::_prioritize_left(std::string& str, int i) {
        if (str[i-1] == ')') {
            int end = i - 2 > 0? i - 2 : 0;
            int loc = _findLeftBracket(str, 0, end);
            str.insert(loc, "(");
        } else if (_isNumber(str[i-1])) {
            int loc = _findTermStart(str, i-1);
            str.insert(loc, "("); 
        }
    }

    // inserts right bracket for the prioritized expression
    void Parser::_prioritize_right(std::string& str, int i) {
        if (str[i+1] == '(') {
            int start = i+2 < str.length()-1 ? i + 2 : str.length()-1;  
            int loc = _findRightBracket(str, start, str.length()-1);
            str.insert(loc, ")");
        } else if (_isNumber(str[i+1])) {
            int loc = _findTermEnd(str, i+1);
            if (loc == str.length()) 
                str += ")";
            else 
                str.insert(loc+1, ")"); // need to find the end of the number
        }
    }

    bool Parser::_isOperator(const char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    bool Parser::_isNumber(const char ch) {
	    return ch > 47 && ch < 58;
    }
}