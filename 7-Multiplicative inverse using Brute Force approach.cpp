#include <stdio.h>

int isMultiplicativeInverse(int a, int b, int m);

int main()
{
    int a, b, m;

    // Input values
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter the value of m: ");
    scanf("%d", &m);

    // Check if b is the multiplicative inverse of a modulo m
    if (isMultiplicativeInverse(a, b, m))
    {
        printf("%d is the multiplicative inverse of %d modulo %d.\n", b, a, m);
    }
    else
    {
        printf("%d is not the multiplicative inverse of %d modulo %d.\n", b, a, m);
    }
     printf("Name: Kopila Devkota\n");
     printf("Roll no: 28371/078");
    return 0;
}

// Function to check if b is the multiplicative inverse of a modulo m
int isMultiplicativeInverse(int a, int b, int m)
{
    return ((a * b) % m == 1);
}