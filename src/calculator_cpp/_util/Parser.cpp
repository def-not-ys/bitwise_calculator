#include "Parser.h"

namespace AST {

    Parser::~Parser() {}

    void Parser::visit(Expression* node) {
        std::string expr = node->_expression;

 #if DEBUG_ON
        std::cout << "parsing:: " << expr << std::endl;
 #endif //DEBUG_ON

        int _loc = _findExpressionsLocation(expr);

        Node* next_node = nullptr;

        if (_loc < 0) {
            node->_expression = expr;
        }
        else if (_loc == (int)expr.length()) {
            next_node = new Expression(expr);
        }
        else {
            Expression* l = new Expression(expr.substr(0,_loc - 1));
            Expression* r = new Expression(expr.substr(_loc));
            char op = expr[_loc-1];

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
        node->_left->accept(this);
        node->_right->accept(this);
    }

    void Parser::visit(Minus* node) {
        node->_left->accept(this);
        node->_right->accept(this);
    }

    void Parser::visit(Multiply* node) {
        node->_left->accept(this);
        node->_right->accept(this);
    }

    void Parser::visit(Divide* node) {
        node->_left->accept(this);
        node->_right->accept(this);
    }

    void Parser::prioritize(std::string& str) {
        unsigned int i = 0;
        if (str.length() < 1 || _isOperator(str[0]))
            str = "0" + str;
        _checkImplicitMultiply(str);
        while (i < str.length()) {

            if (_isInvalid(str[i]))
                throw ASTError("ParserError::invalid input");

            if (i+1 < str.length() && _isOperator(str[i]) && _isOperator(str[i+1]))
                throw ASTError("ParserError::invalid expression");

            if (str[i] == '*' || str[i] == '/') {
                    _prioritize_left(str, i);
                    i++;
                    _prioritize_right(str, i);
            }
            i++;
        }
    }

    int Parser::_findExpressionsLocation(std::string& str) {
        int _loc = str.length() - 1;

        if (_loc < 0)
            throw ASTError("ParserError::empty string");

        if (str[_loc] == ')') {
            str.erase(_loc, 1);
            _loc = _findLeftBracket(str, 0, str.length());
            if (_loc <= 0) _loc = 0;
            str.erase(_loc, 1);
            // _loc--;
        }
        else
            _loc = _findTermStart(str, str.length()-1);

        if (_loc <= 0)
            _loc = _isNumber(str) ? -1 : str.length();

        return _loc;
    }

    int Parser::_findRightBracket(const std::string &str, int sub_start, int sub_end) {
        std::string s = str.substr(sub_start, sub_end);
		int _rb = 1, _loc = 0;
		while (_rb && _loc < (int)s.length()) {
            if (s[_loc] == ')' )
                    _rb--;
            else if (s[_loc] == '(')
                    _rb++;
            _loc++;
		}
        if (_rb != 0)
            throw ASTError("ParserError::unbalanced brackets");
        return _loc+sub_start-1;
    }

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
            throw ASTError("ParserError::unbalanced brackets");
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
		while (_loc++ < (int)str.length()) {
			if (_isOperator(str[_loc]))
				break;
		}
        return _loc-1;
    }

    void Parser::_checkImplicitMultiply(std::string& str) {
        unsigned int i = 1;
        while (i < str.length()-1) {
            if (str[i] == '(') {
                if (_isDigit(str[i-1]))
                    str.insert(i, "*");
            }	else if (str[i] == ')') {
                if (!_isOperator(str[i+1]) && str[i+1] != ')')
                    str.insert(i+1, "*");
            }
            i++;
        }
    }

    void Parser::_prioritize_left(std::string& str, int i) {
        if (str[i-1] == ')') {
            int end = i - 2 > 0? i - 2 : 0;
            int loc = _findLeftBracket(str, 0, end);
            str.insert(loc, "(");
        } else if (_isDigit(str[i-1])) {
            int loc = _findTermStart(str, i-1);
            str.insert(loc, "(");
        }
    }

    void Parser::_prioritize_right(std::string& str, int i) {
        if (str[i+1] == '(') {
            int start = i+2 < (int)str.length()-1 ? i + 2 : (int)str.length()-1;
            int loc = _findRightBracket(str, start, str.length()-1);
            str.insert(loc, ")");
        } else if (_isDigit(str[i+1])) {
            int loc = _findTermEnd(str, i+1);
            if (loc == (int)str.length())
                str += ")";
            else
                str.insert(loc+1, ")");
        }
    }

    bool Parser::_isOperator(const char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    bool Parser::_isDigit(const char ch) {
	    return ch > 47 && ch < 58;
    }

    bool Parser::_isNumber(const std::string str) {
        auto it = str.begin();
        while (it != str.end() && _isDigit(*it)) ++it;
        return it == str.end();
    }

    bool Parser::_isInvalid(const char ch) {
        if (!_isOperator(ch) && !_isDigit(ch) && ch != '(' && ch != ')')
            return true;
        else
            return false;
    }

}