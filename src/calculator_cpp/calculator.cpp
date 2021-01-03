#include "Calculator.h"

std::string test() {
    return "hello from ui";
}

Calculator::Calculator() {};

Calculator::~Calculator() {};


// remove spaces in input string
void Calculator::_format(std::string& str) {
	int i = 0;
	while (i < str.length()) {
		if (str[i] == ' ')
			str.erase(i, 1);
		else 
			i++;
	}
}