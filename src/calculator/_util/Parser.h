#ifndef PARSER_HEADER
#define PAER_HEADER

#include "AST.h"
#include "ParseError.cpp"

namespace AST {
    class Parser: public Visitor {
        public:
            void visit(Expression* node);
            void visit(Add* node);
            void visit(Minus* node);
            void visit(Multiply* node);
            void visit(Divide* node);

            void prioritize(std::string& str);

            int test(); // !!!
        protected:
            int _findExpressionsLocation(std::string& str); 
            int _findRightBracket(const std::string &str, int sub_start, int sub_end);
            int _findLeftBracket(const std::string &str, int sub_start, int sub_end);
            int _findTermStart(std::string &str, int loc);
            int _findTermEnd(std::string &str, int loc);
            void _checkImplicitMultiply(std::string& str);
            void _prioritize_left(std::string& str, int i);
            void _prioritize_right(std::string& str, int i);
            bool _isOperator(const char ch);
            bool _isNumber(const char ch);

    };
}

#endif