#include <stdio.h>
#include <stdbool.h>

// Function to print the subset that sums to the target
void printSubset(int subset[], int subset_size) {
    printf("Subset that sums to target:\n");
    for (int i = 0; i < subset_size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Recursive function to find the subset with given sum using backtracking
bool isSubsetSum(int set[], int n, int sum, int subset[], int subset_size, int index) {
    if (sum == 0) {
        printSubset(subset, subset_size);
        return true;
    }

    if (index >= n || sum < 0) {
        return false;
    }

    // Include the current element in the subset
    subset[subset_size] = set[index];
    if (isSubsetSum(set, n, sum - set[index], subset, subset_size + 1, index + 1)) {
        return true;
    }

    // Exclude the current element from the subset and move to the next element
    return isSubsetSum(set, n, sum, subset, subset_size, index + 1);
}

// Function to initialize subset search
void subsetSum(int set[], int n, int sum) {
    int subset[n]; // To store the subset elements
    isSubsetSum(set, n, sum, subset, 0, 0);
}

int main() {
    int set[] = {3,4, 5, 6};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 9;
    subsetSum(set, n, sum);
    return 0;
}
