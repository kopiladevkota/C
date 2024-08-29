#include <stdio.h>

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    int x, y;
    int a, b;
    char choice;

    do
    {
        // Taking input from the user
        printf("Enter the first number: ");
        scanf("%d", &a);
        printf("Enter the second number: ");
        scanf("%d", &b);

        // Ensure positive integers
        if (a <= 0 || b <= 0)
        {
            printf("Please enter positive integers only.\n");
            continue; // Restart the loop if invalid input
        }

        int g = gcdExtended(a, b, &x, &y);
        printf("gcd(%d, %d) = %d\n", a, b, g);
        printf("Coefficients: x = %d, y = %d\n", x, y);

        // Prompt for continuation
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice); // Notice the space before %c to consume newline

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program...\n");
    printf("Name: Kopila Devkota\n");
           printf("Roll no : 28371/078");

    return 0;
}

