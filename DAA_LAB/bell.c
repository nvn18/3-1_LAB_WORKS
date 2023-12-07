
#include <stdio.h>
#include <limits.h>
#define MAX_VERTEX 100
#define MAX_EDGE 100

void bellman(int V , int E , int edge[][3], int src)
{
    int dist[MAX_VERTEX];
    for(int i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u = edge[j][0];
            int v = edge[j][1];
            int wt = edge[j][2];
            
            if(dist[u]!=INT_MAX && dist[u]+wt < dist[v])
               dist[v] = dist[u] + wt;
        }
    }
    
    for(int i=0;i<E;i++)
        {
            int u = edge[i][0];
            int v = edge[i][1];
            int wt = edge[i][2];
            
            if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
              printf("-ve cycle");
              
            }
        }
    printf("the solution is:");
    for(int i=0;i<V;i++)
    {
        printf("%d \t\t %d\n",i,dist[i]);
    }
            
}
int main()
{
    int V = 5;
    int E = 8;
    
    int edge[MAX_EDGE][3] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    
    int src = 0;
    
    bellman(V,E,edge,src);
    
    return 0;
}

