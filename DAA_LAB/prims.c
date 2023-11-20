#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_V 10
int minKey(int key[], int mst[], int vertice) {
    int min = INT_MAX, min_index;
    for (int k = 0; k < vertice; k++) {
        if (mst[k] == 0 && key[k] < min) {
            min = key[k];
            min_index = k;
        }
    }
    return min_index;
}
//printing the constructed MST
void printMST(int big[], int g[][MAX_V], int vertice) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertice; i++) {
        printf("%d - %d \t%d \n", big[i], i, g[i][big[i]]);
    }
}
// constructing and printing MST 
void primMST(int g[][MAX_V], int vertice) {
    int big[MAX_V]; 
    int key[MAX_V];    
    int mst[MAX_V];
    for (int i = 0; i < vertice; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }
    key[0] = 0;      
    big[0] = -1;  
    for (int i=0; i< vertice - 1; i++) {
        int m = minKey(key, mst, vertice);
        mst[m] = 1;
        for (int k = 0; k < vertice; k++) {
        
            if (g[m][k] && mst[k] == 0 && g[m][k] < key[k]) {
                big[k] = m;
                key[k] = g[m][k];
            }
        }
    }
    // Print the constructed MST
    printMST(big, g, vertice);
}
int main() {
    int vertice;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertice);

    int g[MAX_V][MAX_V];
    
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < vertice; i++) {
        for (int j = 0; j < vertice; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    primMST(g, vertice);

    return 0;
}

