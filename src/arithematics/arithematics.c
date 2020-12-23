#include <stdio.h>
#include <assert.h> 
#include "arithematics.h"

// rertuns two's complement of x
int twos_complement(int x) {
    int result = addition_integer(~x, 1);
    
    assert(result == -x);

    return result;
}

// returns 1 if x > y; 0 if x = y; -1 if x < y
int compare(const int x, const int y) {
    int check = subtraction_integer(x, y);
    if (check & NEGATIVE_MASK)
        return -1;
    else if (check ^ ZERO_MASK)
        return 1;
    else return 0;
}

// returns the absolute value of x 
int abs(const int x) {
    if (x & NEGATIVE_MASK) 
        return twos_complement(x);
    else 
        return x;
}

// retruns 1 if x == 0, 0 otherwise
int is_zero(const int x) {
    if (x ^ 0)
        return 0;
    else 
        return 1;
}

// returns x + y
int addition_integer(const int x, const int y) {

    int carry = (x & y) << 1;
    int _xor = x ^ y;

    while (carry) {
        int tmp_carry = _xor & carry;
        _xor = _xor ^ carry;
        carry = tmp_carry << 1;        
    }

    assert(_xor == x + y);

    return _xor;
}

// returns x - y
int subtraction_integer(const int x, const int y) {
    int result = addition_integer(x, twos_complement(y));

    assert(result == x - y);
    
    return result;
}

// returns x * y
int multiplication_integer(const int x, const int y) {
    int result = 0, remain = y;
    int (*func)(int a, int b) = addition_integer;

    if (remain & NEGATIVE_MASK) {
        remain = twos_complement(remain);
        func = subtraction_integer;
    }
    
    while (remain) {
        result = func(result, x);
        remain = subtraction_integer(remain, 1);
    }

    assert(result == x * y);

    return result;
}

// returns x / y (naive)
int division_integer_naive(const int x, const int y) {
    int dividend = abs(x), divisor = abs(y), quotient = 0, remainder = 0, result = 0, factor = 0;

    assert(divisor != 0);

    int sign = (x & NEGATIVE_MASK) ^ (y & NEGATIVE_MASK);
    int check = compare(dividend, divisor);
    
    if (check & NEGATIVE_MASK | is_zero(dividend) | is_zero(check))
        factor = quotient;
    else {
        while (check & is_zero(check & NEGATIVE_MASK)) {
            result = addition_integer(result, divisor);
            factor = addition_integer(factor, 1);
            check = compare(dividend, result);
        }
        factor = is_zero(check)? factor : subtraction_integer(factor,1);
        if (sign) 
            factor = twos_complement(factor);
    }

    assert(factor == x/y);

    return factor;
}

// returns x / y (restoring)
int division_integer_restoring(const int x, const int y) {
    int sign = (x & NEGATIVE_MASK) ^ (y & NEGATIVE_MASK);
    int dividend = 0, divisor = abs(y), quotient = abs(x), result = 0, factor = 0;
    
    assert(divisor != 0);

    int n = 32, temp = quotient;
    while ((temp & NEGATIVE_MASK) ^ NEGATIVE_MASK) {
        temp <<= 1;
        n = subtraction_integer(n, 1);
    }

    int pos = subtraction_integer(n, 1);
    int msb_mask = 0x1 << pos;

    while (n) {
        int msb = (quotient & msb_mask) >> pos;      

        quotient <<= 1;
        dividend <<= 1;
        dividend |= msb;
        factor <<= 1;

        result = subtraction_integer(dividend, divisor);

        if (is_zero(result & NEGATIVE_MASK)) {
            factor |= 1;
            dividend = result;
        }
        n = subtraction_integer(n, 1);
    }

    if (sign) 
        factor = twos_complement(factor);

    assert(factor == x / y);

    return factor;
}
