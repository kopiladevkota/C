
#include <stdio.h>

int factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int n =7;
    printf("Factorial of %d is %d", n, factorial_iterative(n));
    return 0;
}