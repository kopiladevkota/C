#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    
    // Build the LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    // Length of LCS is L[m][n]
    int lcs_length = L[m][n];
    
    // Find LCS sequence
    char lcs_sequence[MAX_SIZE];
    int index = lcs_length;
    lcs_sequence[index] = '\0'; // Null terminate the sequence
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_sequence[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    // Print results
    printf("Length of LCS is %d\n", lcs_length);
    printf("LCS Sequence is %s\n", lcs_sequence);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";
    int m = strlen(X);
    int n = strlen(Y);
    
    lcs(X, Y, m, n);
    
    return 0;
}
