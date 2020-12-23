// #include <stdio.h>
// #include <stdint.h>

#include "./arithematics/arithematics.h"
#include "./ui/ui.h"

#include <iostream>


int main() {

    // int sum1 = 50000, sum2 = 20;

    // for (int i = 1; i < 500; i++) {
    //     if (i & 1) sum1 = multiplication_integer(sum1, i);
    //     else sum1 = division_integer_naive(sum1, i); 

    //     // printf("sum1 = %d \t i = %d\n", sum1, i);
    // }

    // printf("sum1 = %d \t sum2 = %d\n", sum1, sum2);

    std::cout << "complied in c++" << std::endl;

    int a = addition_integer(1,2);
    
    std::cout << "caculator : " << a << std::endl;

    std::cout << test() << std::endl;

    return 0;
}