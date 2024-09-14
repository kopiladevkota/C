#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int min(int a, int b, int c) {
    int min_ab = (a < b) ? a : b;
    return (min_ab < c) ? min_ab : c;
}

int levenshteinDistance(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int D[MAXLEN][MAXLEN];

    // Initialize D[i][0] and D[0][j]
    for (int i = 0; i <= m; i++) {
        D[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        D[0][j] = j;
    }

    // Fill in the rest of the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                D[i][j] = D[i - 1][j - 1];
            } else {
                D[i][j] = 1 + min(D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]);
            }
        }
    }

    // The minimum edit distance is found in D[m][n]
    return D[m][n];
}

int main() {
    char str1[] = "devkota";
    char str2[] = "khatiwada";

    int distance = levenshteinDistance(str1, str2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}
