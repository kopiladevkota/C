
#include <stdio.h>
#include <stdlib.h>
// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;
// Structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;
// Function to find the root of an element with path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
// Function to perform union of two subsets by rank
void union_subsets(Subset subsets[], int x, int y) {
    int root_x = find(subsets, x);
    int root_y = find(subsets, y);
    if (subsets[root_x].rank < subsets[root_y].rank)
        subsets[root_x].parent = root_y;
    else if (subsets[root_x].rank > subsets[root_y].rank)
        subsets[root_y].parent = root_x;
    else {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

// Comparator function to sort edges by weight
int compare_edges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Function to construct MST using Kruskal's algorithm
void kruskal_mst(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(Edge), compare_edges); // Sort edges by weight
    Subset *subsets = (Subset*) malloc(V * sizeof(Subset));

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("Edges in the MST:\n");
    int e = 0; // Index for result
    for (int i = 0; e < V - 1 && i < E; i++) {
        Edge next_edge = edges[i];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause cycle, include it
        if (x != y) {
            printf("%d -- %d == %d\n", next_edge.src, next_edge.dest, next_edge.weight);
            union_subsets(subsets, x, y);
            e++;
        }
    }
    free(subsets);
}
int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    kruskal_mst(edges, V, E);
    return 0;}