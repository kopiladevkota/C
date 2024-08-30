#include <stdio.h>
#include <stdlib.h>

int modExp(int base, int exponent, int modulus)
{
    if (exponent == 0)
        return 1;
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1; // Right shift exponent by 1
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
    int p, g, a, b;
    char choice;

    do
    {
        printf("Enter a prime number (p): ");
        scanf("%d", &p);

        printf("Enter a primitive root (g) modulo %d: ", p);
        scanf("%d", &g);

        printf("Enter Alice's private key (a): ");
        scanf("%d", &a);

        printf("Enter Bob's private key (b): ");
        scanf("%d", &b);

        int A = modExp(g, a, p); // Calculate Alice's public key
        int B = modExp(g, b, p); // Calculate Bob's public key

        int s1 = modExp(B, a, p); // Calculate shared secret key for Alice
        int s2 = modExp(A, b, p); // Calculate shared secret key for Bob

        if (s1 == s2)
            printf("Shared secret key: %d\n", s1);
        else
            printf("Key exchange failed!\n");

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any trailing newline character
        if (choice == 'n' || choice == 'N')
            break;

    } while (1);
      printf("Name: Kopila Devkota\n");
           printf("Roll no : 28371/078");


    return 0;
}

