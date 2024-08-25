#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to generate the key in a cyclic manner
void generateKey(const char *str, const char *keyword, char *key)
{
    int strLen = strlen(str);
    int keywordLen = strlen(keyword);

    for (int i = 0, j = 0; i < strLen; i++)
    {
        if (isalpha(str[i]))
        {
            key[i] = toupper(keyword[j % keywordLen]);
            j++;
        }
        else
        {
            key[i] = str[i];
        }
    }
    key[strLen] = '\0';
}

// Function to return the encrypted text
void cipherText(const char *str, const char *key, char *cipher_text)
{
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(str[i]))
        {
            // Convert to uppercase and perform the encryption
            char x = (toupper(str[i]) - 'A' + key[i] - 'A') % 26;
            x += 'A';  // Convert into alphabet (ASCII)
            cipher_text[i] = x;
        }
        else
        {
            cipher_text[i] = str[i];
        }
    }
    cipher_text[n] = '\0';
}

// Function to decrypt the encrypted text and return the original text
void originalText(const char *cipher_text, const char *key, char *orig_text)
{
    int n = strlen(cipher_text);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(cipher_text[i]))
        {
            // Convert to uppercase and perform the decryption
            char x = (toupper(cipher_text[i]) - toupper(key[i]) + 26) % 26;
            x += 'A';  // Convert into alphabet (ASCII)
            orig_text[i] = x;
        }
        else
        {
            orig_text[i] = cipher_text[i];
        }
    }
    orig_text[n] = '\0';
}

int main()
{
    char str[100], keyword[100], key[100], cipher_text[100], orig_text[100];

    while (1)
    {
        printf("Menu:\n");
        printf("1. Encrypt Text\n");
        printf("2. Decrypt Text\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the plain text: ");
            scanf(" %[^\n]", str);
            printf("Enter the keyword (string): ");
            scanf("%s", keyword);

            generateKey(str, keyword, key);
            cipherText(str, key, cipher_text);

            printf("Encrypted Text: %s\n", cipher_text);
        }
        else if (choice == 2)
        {
            printf("Enter the cipher text: ");
            scanf(" %[^\n]", cipher_text);
            printf("Enter the keyword (string): ");
            scanf("%s", keyword);

            generateKey(cipher_text, keyword, key);
            originalText(cipher_text, key, orig_text);

            printf("Decrypted Text: %s\n", orig_text);
        }
        else if (choice == 3)
            break;
        else
            printf("Invalid choice. Please enter a valid option.\n");
    }

    printf("Name: Kopila Devkota\n");
    printf("Roll no : 28371/078\n");

    return 0;
}
