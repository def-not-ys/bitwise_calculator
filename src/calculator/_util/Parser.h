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

            int test();
        protected:
            int _findExpressionsLocation(std::string& str); 
            int _findRightBracket(std::string &str);
            int _findFirstTerm(std::string &str);
            bool _isOperator(const char ch);

    };
}

#endif