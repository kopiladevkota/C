#include <stdio.h>
#include <limits.h>

#define V 3 // Number of vertices in the graph and infinity is represented as int_max

void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V]; // Output matrix where dist[i][j] will contain the shortest distance from i to j

    // Initialize the distance matrix with graph values
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < V; k++) { // Intermediate vertex
        for (int i = 0; i < V; i++) { // Source vertex
            for (int j = 0; j < V; j++) { // Destination vertex
                // If vertex k is an intermediate vertex on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

int main() {
    // Custom input graph as per your format: {0 4 11},{6 0 2},{3 inf 0}
    int graph[V][V] = {{0, 4, 11},
                       {6, 0, 2},
                       {3, INT_MAX, 0}};

    floydWarshall(graph);
    return 0;
}
