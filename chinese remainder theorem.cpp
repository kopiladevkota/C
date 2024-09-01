#include <stdio.h>

// Function to find the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find modular inverse of a under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist if we reach here
}

// Function to find x using the Chinese Remainder Theorem
int findX(int num[], int rem[], int k) {
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    // Initialize result
    int result = 0;

    // Apply the formula
    for (int i = 0; i < k; i++) {
        int Ni = prod / num[i];
        int Mi = modInverse(Ni, num[i]);
        result += rem[i] * Ni * Mi;
    }

    return result % prod;
}

// Driver program to test above functions
int main() {
    int num[] = {5, 7, 11};
    int rem[] = {1, 1, 3};
    int k = sizeof(num) / sizeof(num[0]);
    int x = findX(num, rem, k);
    printf("The solution is %d\n", x);
    return 0;
}
