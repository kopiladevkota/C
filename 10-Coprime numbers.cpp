#include <stdio.h>
#include <conio.h>

int main()
{
    char choice;
    do
    {
        int num1, num2, hcf, i;

        printf("Enter two numbers:\n");
        scanf("%d%d", &num1, &num2);

        // Finding HCF
        for (i = 1; i <= num1 && i <= num2; i++)
        {
            if (num1 % i == 0 && num2 % i == 0)
            {
                hcf = i;
            }
        }

        // Making Decision
        if (hcf == 1)
        {
            printf("%d and %d are CO-PRIME NUMBERS.\n", num1, num2);
        }
        else
        {
            printf("%d and %d are NOT CO-PRIME NUMBERS.\n", num1, num2);
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program...\n");
               printf("Name: Kopila Devkota\n");
           printf("Roll no : 28371/078");

    getch(); // Using getch() to hold the output window open in Windows

    return 0;
}
