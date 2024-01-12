#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the solution array
void printSolution(int dist[]) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t INFINITY\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

// Function to perform Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    // Initialize distances and set of vertices included in the shortest-path tree
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance from the source vertex to itself is always 0
    dist[src] = 0;

    // Find the shortest paths for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        // Update dist value of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != INT_MAX &&
                dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the solution
    printSolution(dist);
}

int main() {
    // Example graph represented by an adjacency matrix
    int graph[V][V] = {
        {0, 2, INT_MAX, 1, INT_MAX, INT_MAX},
        {2, 0, 4, 4, INT_MAX, INT_MAX},
        {INT_MAX, 4, 0, 3, 5, INT_MAX},
        {1, 4, 3, 0, 4, 3},
        {INT_MAX, INT_MAX, 5, 4, 0, 7},
        {INT_MAX, INT_MAX, INT_MAX, 3, 7, 0}
    };

    // Apply Dijkstra's algorithm
    dijkstra(graph, 0);

    return 0;
}
