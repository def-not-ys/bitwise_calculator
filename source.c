#include <stdio.h>
#include <stdint.h>
#include "calculator.h"


int main() {

    int sum1 = 50000, sum2 = 20;

    for (int i = 1; i < 500; i++) {
        if (i & 1) sum1 = multiplication_integer(sum1, i);
        else sum1 = division_integer_naive(sum1, i); 

        // printf("sum1 = %d \t i = %d\n", sum1, i);
    }

    printf("sum1 = %d \t sum2 = %d\n", sum1, sum2);

    return 0;
}