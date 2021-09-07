# bitwise_calculator
a silly calculator implemented using bitwise operators and the visitor design pattern.
not meant to be useful. 

## General information
This project consists of two main parts:
### Arithmetic operations 
Basic arithmatic operations `addtion`, `subtraction`, `multiplication`, and `division` are implemented using **only** bitwise operators to simulate how calculation would be done on hardware.The arithematic operations are written in C at `src/arithematics`. 
### Math parser
The math parser for the calculator is written in C++ and implemented the Visitor design parttern for an abstract syntax tree (AST). 

## Current state and improvements
The parser now parses mathmatical expressions of `+, -, *, /` operations on integers and the order of operation can be prioritized with `()`. 

Some of the limitations and potential improvements: 
* negative numbers are entered without `()` are not properly parsed. e.g.
```
5 + (-2) = 3 // parsed and processed correctly
5 + - 2 = error // not able to parse
```
* to add modulo operation supporr `%`
* support for non-integer





























