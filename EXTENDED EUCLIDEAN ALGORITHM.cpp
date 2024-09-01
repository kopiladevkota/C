
#include <stdio.h>

int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    int a = 161, b = 28, x, y;
    int gcd = extendedGCD(a, b, &x, &y);
    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    printf("Coefficients: x = %d, y = %d\n", x, y);
    return 0;
}