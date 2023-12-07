#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the final distances from the source
void printSolution(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;  // Distance from the source to itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the final distances
    printSolution(dist, V);
}

int main() {
    int V = 6;  // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 4, 0, 0, 0},
        {1, 0, 4, 2, 7, 0},
        {4, 4, 0, 3, 5, 0},
        {0, 2, 3, 0, 4, 6},
        {0, 7, 5, 4, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };

    int src = 0;  // Source vertex

    dijkstra(graph, src, V);

    return 0;
}

