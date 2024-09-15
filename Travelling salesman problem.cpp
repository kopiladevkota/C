#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the TSP using dynamic programming
int tsp(int graph[][4], int path[], int n, int pos, int visited, int **dp) {
    // If all cities have been visited, return to starting city
    if (visited == ((1 << n) - 1))
        return graph[pos][0];
    
    // If this state has already been computed, return the stored value
    if (dp[visited][pos] != -1)
        return dp[visited][pos];

    int ans = INT_MAX;
    int next_city = -1;

    // Try to go to every other city from the current position
    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) { // If city 'city' is not visited
            int newAns = graph[pos][city] + tsp(graph, path, n, city, visited | (1 << city), dp);
            if (newAns < ans) {
                ans = newAns;
                next_city = city;
            }
        }
    }

    // Store the optimal path for the current state
    path[visited] = next_city;

    // Memoize the computed answer
    return dp[visited][pos] = ans;
}

// Function to print the optimal path found
void printPath(int path[], int n) {
    printf("Path: ");
    int current = 0;
    int visited = 1;
    for (int i = 0; i < n - 1; i++) {
        printf("%d -> ", current);
        current = path[visited];
        visited |= (1 << current);
    }
    printf("%d -> %d\n", current, 0); // Return to starting city
}

int main() {
    int graph[4][4] = {{0, 10, 15, 20},
                       {5, 0, 9, 10},
                       {6, 13, 0, 12},
                       {8, 8, 9, 0}};
    int n = 4;
    int path[1 << n]; // Array to store the path
    int **dp = (int **)malloc((1 << n) * sizeof(int *));
    for (int i = 0; i < (1 << n); i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }

    // Calculate minimum cost
    int min_cost = tsp(graph, path, n, 0, 1, dp);
    printf("Minimum cost is %d\n", min_cost);

    // Print the path
    printPath(path, n);

    // Free dynamically allocated memory
    for (int i = 0; i < (1 << n); i++)
        free(dp[i]);
    free(dp);

    return 0;
}
