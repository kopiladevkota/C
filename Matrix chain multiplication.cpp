#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications needed to multiply the sequence of matrices
void matrixChainOrder(int p[], int n) {
    int m[n][n];    // m[i][j] will store the minimum number of scalar multiplications needed to compute A_i * A_{i+1} * ... * A_j
    int s[n][n];    // s[i][j] will store the index of the matrix that achieved the minimum multiplication count
    
    // Initialize m[i][i] to 0 because no multiplication is needed for a single matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n-1]);
}

int main() {
    int arr[] = {30, 35, 15, 5, 10, 20, 25}; // Dimensions of matrices A1, A2, ..., An
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, n);

    return 0;
}
