#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 5

// Struct to represent each item
struct Item {
    int weight;
    int value;
};

// Global variables for simplicity (not ideal for large-scale use)
struct Item items[MAX_ITEMS];
int knapsackCapacity;
int currentWeight = 0;
int currentValue = 0;
int maxPossibleValue = 0;
bool solution[MAX_ITEMS];

// Function to recursively explore all combinations using backtracking
void knapsackBacktrack(int index) {
    if (index == MAX_ITEMS) {
        // Base case: Reached end of items, check if this combination is better
        if (currentValue > maxPossibleValue) {
            maxPossibleValue = currentValue;
            for (int i = 0; i < MAX_ITEMS; ++i) {
                solution[i] = (items[i].weight <= knapsackCapacity);
            }
        }
        return;
    }

    // Include item[index] if it fits in the knapsack
    if (currentWeight + items[index].weight <= knapsackCapacity) {
        currentWeight += items[index].weight;
        currentValue += items[index].value;
        knapsackBacktrack(index + 1);
        currentWeight -= items[index].weight;
        currentValue -= items[index].value;
    }

    // Exclude item[index] and move to the next item
    knapsackBacktrack(index + 1);
}

// Function to solve the 0-1 Knapsack problem using backtracking
void solveKnapsack() {
    knapsackBacktrack(0);

    // Output the solution
    printf("Optimal Solution:\n");
    printf("Item\tWeight\tValue\tInclude\n");
    for (int i = 0; i < MAX_ITEMS; ++i) {
        printf("%d\t%d\t%d\t%s\n", i + 1, items[i].weight, items[i].value, solution[i] ? "Yes" : "No");
    }
    printf("Total Value: %d\n", maxPossibleValue);
}

int main() {
    // Example items
    items[0].weight = 3; items[0].value = 45;
    items[1].weight = 5; items[1].value = 30;
    items[2].weight = 9; items[2].value = 45;
    items[3].weight = 5; items[3].value = 10;
  

    // Example knapsack capacity
    knapsackCapacity = 16;

    // Solve the knapsack problem
    solveKnapsack();

    return 0;
}
