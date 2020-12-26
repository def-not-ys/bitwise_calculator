
namespace AST {
    template<typename T>
    struct Visitable {
    };

    template<typename T>
    struct Visitor<T> {
        virtual T visit(Visitable* visitable) const = 0;
    };
}
