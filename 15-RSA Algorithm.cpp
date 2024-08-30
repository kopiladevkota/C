#include <stdio.h>
#include <math.h>

// Function to find gcd
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main()
{
    // 2 random prime numbers
    double p, q;
    char choice;

    do
    {
        printf("Enter two prime numbers: ");
        scanf("%lf %lf", &p, &q);

        double n = p * q;
        double count;
        double totient = (p - 1) * (q - 1);

        // public key - e stands for encrypt
        double e = 2;

        // for checking co-prime which satisfies e > 1
        while (e < totient)
        {
            count = gcd((int)e, (int)totient);
            if (count == 1)
                break;
            else
                e++;
        }

        // private key - d stands for decrypt
        double d;
        // k can be any arbitrary value
        double k = 2;

        // choosing d such that it satisfies d*e = 1 + k * totient
        d = (1 + (k * totient)) / e;

        double msg;
        printf("Enter Message to be encrypted (integer): ");
        scanf("%lf", &msg);

        double c = pow(msg, e);
        double m = pow(c, d);
        c = fmod(c, n);
        m = fmod(m, n);

        printf("p = %f\n", p);
        printf("q = %f\n", q);
        printf("n = pq = %.f\n", n);
        printf("totient = %f\n", totient);
        printf("e = %.f\n", e);
        printf("d = %f\n", d);
        printf("Encrypted data = %f\n", c);
        printf("Original Message sent = %f\n", m);

        printf("Do you want to continue? (y/n): ");
        // Clear the input buffer before reading the choice character
        while (getchar() != '\n')
            ; // Consume all characters in the input buffer
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Name: Kopila Devkota\n");
    printf("Roll no: 28371/078");

    return 0;
}
