#include <stdio.h>
#include <stdint.h>
#include "calculator.h"


int main() {

    int sum1 = 1, sum2 = 500;

    // for (int i = 1; i < 500; i++) {
    //     if (i & 1) sum1 = multiplication_integer(sum1, i);
    //     else sum1 = division_integer(sum1, i); 

    //     // printf("sum1 = %d \t i = %d\n", sum1, i);
    // }

        for (int i = 1; i < 500; i++) {
        if (i & 1) sum1 *= i;
        else sum1 /= i; 

        // printf("sum1 = %d \t i = %d\n", sum1, i);
    }

    printf("sum1 = %d \t sum2 = %d\n", sum1, sum2);

    // printf("%d * %d = %d\n", -5, -5, multiplication_integer(-5,-5));
    // printf("%d * %d = %d\n", 3, 3, multiplication_integer(3,3));
    // printf("%d * %d = %d\n", 0, 99, multiplication_integer(0,99));
    // printf("%d * %d = %d\n", 9, -3, multiplication_integer(9,-3));

    // printf("%d / %d = %d\n", 12, 3, division_integer(12,3));
    // printf("%d / %d = %d\n", 12, 4, division_integer(12,4));

    // printf("%d / %d = %d\n", -12, 3, division_integer(-12,3));
    // printf("%d / %d = %d\n", 12, -4, division_integer(12,-4));
    // printf("%d / %d = %d\n", -12, -2, division_integer(-12,-2));

    return 0;
}