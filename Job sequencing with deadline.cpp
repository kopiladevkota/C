#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparison function for qsort to sort jobs by decreasing profit
int compare(const void *a, const void *b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to print job scheduling and calculate max profit
int print_job_scheduling(struct Job arr[], int n) {
    // Sort jobs by decreasing profit using qsort
    qsort(arr, n, sizeof(struct Job), compare);

    // Initialize arrays for result and slot availability
    int result[n];
    bool slot[n];

    // Initialize all slots to be available
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Fill the result array with scheduled jobs
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;  // Store index of job in the result array
                slot[j] = true; // Mark this slot as filled
                break;
            }
        }
    }

    // Calculate total profit and print scheduled jobs
    int totalProfit = 0;
    printf("Scheduled jobs: ");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%c ", arr[result[i]].id);
            totalProfit += arr[result[i]].profit;
        }
    }
    printf("\n");

    // Return the total profit
    return totalProfit;
}

int main() {
    struct Job arr[] = {{'a', 2, 60}, {'b', 1, 100}, {'c', 3, 20}, {'d', 2, 40}, {'e', 1, 20}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxProfit = print_job_scheduling(arr, n);
    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}
