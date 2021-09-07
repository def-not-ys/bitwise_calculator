#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../calculator_cpp/calculator.h"


TEST_CASE("addition", "simple addition test") {
    Calculator calculator;
    REQUIRE(calculator.processInput("10+23") == 33);
}

TEST_CASE("subtraction", "simple subtraction test") {
    Calculator calculator;
    REQUIRE(calculator.processInput("10-23") == -13);
}

TEST_CASE("multiplication", "simple multiplication test") {
    Calculator calculator;
    REQUIRE(calculator.processInput("10*2") == 20);
}

TEST_CASE("division", "simple division test") {
    Calculator calculator;
    REQUIRE(calculator.processInput("10/2") == 5);
}

TEST_CASE("complex", "complex calculator test") {
    Calculator calculator;
    REQUIRE(calculator.processInput("1 + (2+3-4)*5 / (8+8/(5+1)) ") == 1);
}

TEST_CASE("invalid text", "invalid input text") {
    Calculator calculator;
    try {
        calculator.processInput("this is an invalid string!!");
        FAIL("Should throw invalid input exception");
    } catch (AST::ASTError err) {
        // expected
    }
}

TEST_CASE("invalid expression", "invalid input expression") {
    Calculator calculator;
    try {
        calculator.processInput("5*8+/7+");
        FAIL("Should throw invalid input exception");
    } catch (AST::ASTError err) {
        // expected
    }
}

TEST_CASE("process negative number", "processing negative number") {
    Calculator calculator;
    try {
        REQUIRE(calculator.processInput("6*89/-5") == -106);
    } catch (AST::ASTError err) {
        FAIL("Should not throw any error");
    }
}
