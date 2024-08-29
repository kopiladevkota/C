#include <stdio.h>

int main() {
    int n, i, flag = 0;
    char choice;

    do {
        printf("Enter a positive integer: ");
        scanf("%d", &n);

        // 0 and 1 are not prime numbers
        // change flag to 1 for non-prime number
        if (n == 0 || n == 1) {
            flag = 1;
        } else {
            flag = 0;
            for (i = 2; i <= n / 2; ++i) {
                // if n is divisible by i, then n is not prime
                // change flag to 1 for non-prime number
                if (n % i == 0) {
                    flag = 1;
                    break;
                }
            }
        }

        // flag is 0 for prime numbers
        if (flag == 0) {
            printf("%d is a prime number.\n", n);
        } else {
            printf("%d is not a prime number.\n", n);
        }

        printf("Do you want to check another number? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program...\n");
           printf("Name: Kopila Devkota\n");
           printf("Roll no : 28371/078");

    return 0;
}

