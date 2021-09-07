#ifndef PARSER_HEADER
#define PAER_HEADER

#include "AST.h"

namespace AST {
    class Parser: public Visitor {
        public:

            ~Parser();

            void visit(Expression* node);
            void visit(Add* node);
            void visit(Minus* node);
            void visit(Multiply* node);
            void visit(Divide* node);

            // prioritize operation by inserting brackets
            void prioritize(std::string& str);

        protected:
            // returns the location of the end of the expression
            int _findExpressionsLocation(std::string& str);

            // retrusn the position of the matching right bracket
            int _findRightBracket(const std::string &str, int sub_start, int sub_end);

            // retruns the position of the matching right bracket
            int _findLeftBracket(const std::string &str, int sub_start, int sub_end);

            // returns the localtion of the start of the term (searching from end)
            int _findTermStart(std::string &str, int loc);

            // returns the localtion of the end of the term (searching from start)
            int _findTermEnd(std::string &str, int loc);

            // checks and inserts implicit *
            void _checkImplicitMultiply(std::string& str);

            // inserts left bracket for the prioritized expression
            void _prioritize_left(std::string& str, int i);

            // inserts right bracket for the prioritized expression
            void _prioritize_right(std::string& str, int i);

            bool _isOperator(const char ch);
            bool _isDigit(const char ch);
            bool _isNumber(const std::string str);
            bool _isInvalid(const char ch);

    };
}

#endif