#include <stdio.h>
#include <ctype.h> // Include for tolower function

// Function for the extended Euclidean Algorithm
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

// Function to find the multiplicative inverse of 'a' under modulo 'm'
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);

    // If gcd is not 1, then inverse does not exist
    if (g != 1)
    {
        printf("Inverse doesn't exist as gcd(%d, %d) = %d\n", a, m, g);
        return -1;
    }
    else
    {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        printf("Multiplicative inverse of %d under modulo %d is %d\n", a, m, res);
        return res;
    }
}

int main()
{
    int a, m;
    char choice;

    do
    {
        // Taking input from the user
        printf("Enter the number to find its multiplicative inverse: ");
        scanf("%d", &a);
        printf("Enter the modulo value: ");
        scanf("%d", &m);

        // Ensure positive integer input for 'a' and 'm'
        if (a <= 0 || m <= 0)
        {
            printf("Please enter positive integers for both 'a' and 'm'.\n");
            continue; // Restart the loop to get valid inputs
        }

        // Find the multiplicative inverse modulo 'm'
        modInverse(a, m);

        // Ask if the user wants to continue
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice); // Note the space before %c to consume newline

        // Convert choice to lowercase for case insensitivity
        choice = tolower(choice);

    } while (choice == 'y');

    printf("Exiting the program...\n");
    
           printf("Name: Kopila Devkota\n");
           printf("Roll no : 28371/078");

    return 0;
}

