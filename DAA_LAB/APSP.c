#include <stdio.h>

#define INF 99999
#define MAX_VERT 100

void printSolution(int dist[][MAX_VERT], int V);

void floydWarshall(int graph[][MAX_VERT], int V) {
    int dist[MAX_VERT][MAX_VERT];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);
}

void printSolution(int dist[][MAX_VERT], int V) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF");
            else
                printf("%d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX_VERT][MAX_VERT];
    printf("Enter the adjacency matrix (use INF for no direct edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, V);

    return 0;
}



