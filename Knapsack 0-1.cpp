#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // K[n][W] contains the maximum value that can be obtained with weight limit W
    return K[n][W];
}

int main() {
    int val[] = {2, 3, 1, 4}; // values of items
    int wt[] = {3, 4, 6, 5};    // weights of items
    int W = 8;                 // capacity of knapsack
    int n = sizeof(val) / sizeof(val[0]); // number of items

    printf("Maximum value that can be obtained = %d\n", knapsack(W, wt, val, n));
    return 0;
}
