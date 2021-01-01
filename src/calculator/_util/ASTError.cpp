#include <string>

namespace AST {
    struct ASTError {
        std::string msg;   
        ASTError() : msg("error") {};
        ASTError(std::string m) : msg(m) {};
        std::string getMessage() { return msg; };
    };
}
