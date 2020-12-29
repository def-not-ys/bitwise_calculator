#include <string>

namespace AST {
    struct ParseError {
        std::string msg;   
        ParseError() : msg("error") {};
        ParseError(std::string m) : msg(m) {};
        std::string getMessage() { return msg; };
    };
}
