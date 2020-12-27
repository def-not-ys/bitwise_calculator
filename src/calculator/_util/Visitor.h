
namespace AST {
    template<typename T>
    struct Visitable {
    };

    template<typename T>
    struct Visitor {
        virtual T visit(Visitable* visitable) const = 0;
    };
}
