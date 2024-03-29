#include "Calculator.h"


Calculator::Calculator():  _ans(0), _node(0), _parser(0), _evaluator(0) {}
Calculator::~Calculator() {
	_clear();
}

int Calculator::processInput(const std::string& input) {
	std::string str = input;
	_format(str);

	if (str.length() == 0)
		throw AST::ASTError("empty input");

	_node = new AST::Expression(str);

	_parse();
	_evaluate();
	_clear();

	return _ans;
}


// remove spaces in input string
void Calculator::_format(std::string& str) {
	unsigned int i = 0;
	while (i < str.length()) {
		if (str[i] == ' ')
			str.erase(i, 1);
		else
			i++;
	}
}

void Calculator::_parse() {
	_parser = new AST::Parser;
	_parser->prioritize(_node->_expression);
	_node->accept(_parser);
}

void Calculator::_evaluate() {
	_evaluator = new AST::Evaluator;
	_node->accept(_evaluator);
	_ans = _node->_ans;
}

void Calculator::_clear() {
	if (_node)
		delete _node;
	_node = 0;

	if (_parser)
		delete _parser;
	_parser = 0;

	if (_evaluator)
		delete _evaluator;
	_evaluator = 0;
}