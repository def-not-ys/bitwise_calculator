#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../calculator_cpp/calculator.h"


TEST_CASE("addition", "simple addition test") {
    Calculator calculator;
    REQUIRE(calculator.processInput("10+2") == 12);
}

TEST_CASE("subtraction", "simple subtraction test") {
    Calculator calculator;
    REQUIRE(calculator.processInput("10-2") == 8);
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