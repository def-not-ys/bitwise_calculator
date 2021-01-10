// #include "Parser.h"
// #include "Evaluator.h"

// using namespace AST;

// int main() {
    
//     Parser* p = new Parser();
//     Evaluator e;
//     Visitor* v;
//     v = p;

//     std::cout << "complied!!" << std::endl;
//     // std::cout << v.test() << std::endl; // shouhld error

//     // Add add = Add();
//     // p.visit(&add);
//     // v->visit(&add);
//     // e.visit(&add);

//     // Node* node = &add;
//     std::string input = "(1)+(12)/(3)";

//     try {
//         p->prioritize(input);
//         Expression expr = Expression(input);
//         // expr.accept(p);
//         expr.accept(v);
//         std::cout << std::endl;
//         expr.accept(&e);
//         std::cout << "\nresult: " << expr._ans << "\n" << std::endl;
//     } catch (ASTError err) {
//         std::cout << err.getMessage() << std::endl;
//     }

    
//     // node->accept(&p);
//     // node->accept(v);
//     // node->accept(&e);
    
//     // std::cout << node->_x << std::endl;

//     delete p;

//     std::cout << "\nend" << std::endl;

// }