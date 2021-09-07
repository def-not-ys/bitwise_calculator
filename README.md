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

## How to run?

1) make sure docker is installed.

2) from the project root directory, build docker image:

```
$ docker build -t calculator .
```

3) once the application is built, run docker:
```
$ docker run --interactive --tty calculator
```

example output:

```
$ docker run --interactive --tty calculator
this is a silly calculator, enter expression (e.g. 1+5) or enter 'quit' to quit
8+9
8+9 = 17
7*56
7*56 = 392
quit
bye..
```

## Other thoughts?
contributions welcomed :)



























