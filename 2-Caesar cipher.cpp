#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000
#define KEY 3

void encrypt(char *plaintext, char *ciphertext);
void decrypt(char *ciphertext, char *plaintext);

int main()
{
    int choice;
    char plaintext[MAX_TEXT_LENGTH], ciphertext[MAX_TEXT_LENGTH];

    do
    {
        printf("Menu:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after scanf

        switch (choice)
        {
        case 1:
            printf("Enter the plaintext: ");
            fgets(plaintext, MAX_TEXT_LENGTH, stdin);
            // Remove trailing newline character from fgets
            plaintext[strcspn(plaintext, "\n")] = 0;

            encrypt(plaintext, ciphertext);
            printf("Encrypted Text: %s\n\n", ciphertext);
            break;

        case 2:
            printf("Enter the ciphertext: ");
            fgets(ciphertext, MAX_TEXT_LENGTH, stdin);
            // Remove trailing newline character from fgets
            ciphertext[strcspn(ciphertext, "\n")] = 0;

            decrypt(ciphertext, plaintext);
            printf("Decrypted Text: %s\n\n", plaintext);
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            break;
        }
    } while (choice != 3);

    printf("Name: Kopila Devkota\n");
    printf("Roll no: 28371/078");

    return 0;
}

// Function to encrypt the plaintext using Caesar cipher with a fixed key of 3
void encrypt(char *plaintext, char *ciphertext)
{
    int i;
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            ciphertext[i] = ((plaintext[i] - base + KEY) % 26) + base;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0'; // Null terminate the ciphertext string
}

// Function to decrypt the ciphertext using Caesar cipher with a fixed key of 3
void decrypt(char *ciphertext, char *plaintext)
{
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++)
    {
        if (isalpha(ciphertext[i]))
        {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = ((ciphertext[i] - base - KEY + 26) % 26) + base;
        }
        else
        {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0'; // Null terminate the plaintext string
}
