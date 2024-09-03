#include <stdio.h>
#include <stdlib.h>

// Structure for an item which has weight and value
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio for sorting
int compare(const void* a, const void* b) {
    double ratio1 = (double)(((struct Item*)a)->value) / (((struct Item*)a)->weight);
    double ratio2 = (double)(((struct Item*)b)->value) / (((struct Item*)b)->weight);
    return ratio2 > ratio1 ? 1 : -1;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Sort items based on value-to-weight ratio in descending order
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0; // Total value in the knapsack
    int currentWeight = 0;   // Current weight in the knapsack

    // Iterate through all items
    for (int i = 0; i < n; i++) {
        // If adding the whole item does not exceed capacity, add it fully
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Otherwise, take the fraction of the item that fits
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
