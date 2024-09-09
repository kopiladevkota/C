
#include <stdio.h>
#include <stdlib.h>

int power(int base, unsigned int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int millerTest(int d, int n) {
    int a = 2 + rand() % (n - 4);
    int x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return 1;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
            return 0;
        if (x == n - 1)
            return 1;
    }
    return 0;
}

int isPrime(int n, int k) {
    if (n <= 1 || n == 4)
        return 0;
    if (n <= 3)
        return 1;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return 0;
    return 1;
}

int main() {
    int num = 13;
    int k = 2;
    if (isPrime(num, k))
        printf("%d is prime.\n", num);
    else
        printf("%d is not prime.\n", num);
    return 0;
}