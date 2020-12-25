#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../arithematics/arithematics.h"

TEST_CASE("addition", "integer addition test") {
    REQUIRE(addition_integer(7,5) == 12);
    REQUIRE(addition_integer(-7,5) == -2);
    REQUIRE(addition_integer(7,0) == 7);
}

TEST_CASE("subtraction", "integer subtraction test") {
    REQUIRE(subtraction_integer(7,5) == 2);
    REQUIRE(subtraction_integer(-7,5) == -12);
    REQUIRE(subtraction_integer(7,0) == 7);
}

TEST_CASE("naive multiplication", "naive integer multiplication") {
    REQUIRE(multiplication_integer_naive(7,5) == 35);
    REQUIRE(multiplication_integer_naive(-7,5) == -35);
    REQUIRE(multiplication_integer_naive(7,0) == 0);
}

TEST_CASE("russian_peasant multiplication", "russian_peasant integer multiplication") {
    REQUIRE(multiplication_integer_russian_peasant(7,5) == 35);
    REQUIRE(multiplication_integer_russian_peasant(-7,5) == -35);
    REQUIRE(multiplication_integer_russian_peasant(7,0) == 0);
}

TEST_CASE("naive division", "naive integer division") {
    REQUIRE(division_integer_naive(7,5) == 1);
    REQUIRE(division_integer_naive(-7,5) == -1);
    REQUIRE(division_integer_naive(0,7) == 0);
}

TEST_CASE("restoring division", "restoring integer division") {
    REQUIRE(division_integer_restoring(7,5) == 1);
    REQUIRE(division_integer_restoring(-7,5) == -1);
    REQUIRE(division_integer_restoring(0,7) == 0);
}

// TEST_CASE("exponentiation", "exponentiation tests") {
//     // to do
// }

// TEST_CASE("modulo", "modulo tests") {
//     // to do
// }