#define NEGATIVE_MASK 0x80000000
#define ZERO_MASK 0x00000000

int twos_complement(int x);

int compare(const int x, const int y);
int abs(const int x);
int is_zero(const int x);

int addition_integer(const int x, const int y);
int subtraction_integer(const int x, const int y); 
int multiplication_integer(const int x, const int y);
int division_integer_naive(const int x, const int y);
int division_integer_restoring(const int x, const int y);
int exponentiation_integer(const int base, const int exp);
int modulo_integer(const int x, const int y);

int factorial(int n);