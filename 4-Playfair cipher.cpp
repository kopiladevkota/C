#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30

void toLowerCase(char[], int);
int removeSpaces(char *, int);
void generateKeyTable(char[], int, char[][5]);
void search(char[][5], char, char, int[]);
int mod5(int);
int prepare(char[], int);
void encrypt(char[], char[][5], int);
void encryptByPlayfairCipher(char[], char[]);
void decrypt(char[], char[][5], int);
void decryptByPlayfairCipher(char[], char[]);
void displayKeyMatrix(char[][5]);

int main()
{
    char str[SIZE], key[SIZE];
    char keyT[5][5];

    int choice;
    do
    {
        printf("Menu:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the choice

        switch (choice)
        {
        case 1:
            printf("Enter key text: ");
            fgets(key, SIZE, stdin);
            key[strcspn(key, "\n")] = '\0'; // Remove the trailing newline character

            printf("Enter plain text: ");
            fgets(str, SIZE, stdin);
            str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline character

            // Encrypt and display the cipher text
            encryptByPlayfairCipher(str, key);
            printf("\nCipher text: %s\n", str);
            break;

        case 2:
            printf("Enter key text: ");
            fgets(key, SIZE, stdin);
            key[strcspn(key, "\n")] = '\0'; // Remove the trailing newline character

            printf("Enter cipher text: ");
            fgets(str, SIZE, stdin);
            str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline character

            // Decrypt and display the plain text
            decryptByPlayfairCipher(str, key);
            printf("\nDecrypted text: %s\n", str);
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

// Function to convert the string to lowercase
void toLowerCase(char plain[], int ps)
{
    for (int i = 0; i < ps; i++)
    {
        plain[i] = tolower(plain[i]);
    }
}

// Function to remove all spaces in a string
int removeSpaces(char *plain, int ps)
{
    int count = 0;
    for (int i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

// Function to generate the 5x5 key square
void generateKeyTable(char key[], int ks, char keyT[5][5])
{
    int dicty[26] = {0};
    dicty['j' - 'a'] = 1; // Mark 'j' as already included to avoid it being added

    int i, j, k, index = 0;
    for (i = 0; i < ks; i++)
    {
        if (key[i] != 'j' && dicty[key[i] - 'a'] == 0)
        {
            dicty[key[i] - 'a'] = 1;
            keyT[index / 5][index % 5] = key[i];
            index++;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (dicty[i] == 0)
        {
            keyT[index / 5][index % 5] = (char)(i + 'a');
            index++;
        }
    }
}

// Function to search for the characters of a digraph in the key square and return their position
void search(char keyT[5][5], char a, char b, int arr[])
{
    if (a == 'j')
        a = 'i';
    if (b == 'j')
        b = 'i';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

// Function to find the modulus with 5
int mod5(int a)
{
    return (a + 5) % 5;
}

// Function to make the plain text length to be even
int prepare(char str[], int ptrs)
{
    if (ptrs % 2 != 0)
    {
        str[ptrs++] = 'z';
        str[ptrs] = '\0';
    }
    return ptrs;
}

// Function for performing the encryption
void encrypt(char str[], char keyT[5][5], int ps)
{
    int a[4];

    for (int i = 0; i < ps; i += 2)
    {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

// Function to encrypt using Playfair Cipher
void encryptByPlayfairCipher(char str[], char key[])
{
    int ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    int ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    ps = prepare(str, ps);

    char keyT[5][5];
    generateKeyTable(key, ks, keyT);

    encrypt(str, keyT, ps);
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

// Function to decrypt
void decrypt(char str[], char keyT[5][5], int ps)
{
    int a[4];
    for (int i = 0; i < ps; i += 2)
    {
        search(keyT, str[i], str[i + 1], a);
        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] - 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] - 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] - 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] - 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }

    // Remove the padding 'z' if it was added during encryption
    if (ps % 2 == 0 && str[ps - 1] == 'z')
    {
        str[ps - 1] = '\0';
    }
}

// Function to call decrypt
void decryptByPlayfairCipher(char str[], char key[])
{
    int ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    int ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    char keyT[5][5];
    generateKeyTable(key, ks, keyT);

    decrypt(str, keyT, ps);
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

// Function to display the key matrix
void displayKeyMatrix(char keyT[5][5])
{
    printf("Key Matrix:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", toupper(keyT[i][j]));
        }
        printf("\n");
    }
}
