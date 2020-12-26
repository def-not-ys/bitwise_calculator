#include "Visitor.h"

namespace AST {
    template<typename T>
    struct Node: public Visitable<T>{
        Node();
        virtual ~Node();         
        virtual T accept(const Visitor<T>* v) const;

        int _x, _y, _ans;
    };

    template<typename T>
    struct Expression: public Node {
        // todo
        T accept(const Visitor<T>* v) const {
            // stub
        }
    };

    template<typename T>
    struct Add: public Node {
        // todo
        T accept(const Visitor<T>* v) const {
            // stub 
        }
    };

    template<typename T>
    struct Minus: public Node {
        // todo
        T accept(const Visitor<T>* v) const {
            // stub
        }
    };

    template<typename T>
    struct Multiply: public Node {
        // todo
        T accept(const Visitor<T>* v) const {
            // stub 
        }
    };

    template<typename T>
    struct Divide: public Node {
        // todo
        T accept(const Visitor<T>* v) const {
            // stub 
        }
    };

}