#include <stdio.h>
#include <limits.h>

#define MAX 100

int adj[MAX][MAX];

void primMST(int V) {
    int parent[MAX], key[MAX], mstSet[MAX] = {0};
    int totalWeight = 0;
    for (int i = 0; i < V; i++) key[i] = INT_MAX;
    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u = -1;
        for (int i = 0; i < V; i++)
            if (!mstSet[i] && key[i] < min)
                min = key[i], u = i;

        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
    }

    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, adj[i][parent[i]]);
        totalWeight += adj[i][parent[i]];
    }
    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    int V, E, u, v, w;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = adj[v][u] = w;
    }

    primMST(V);
    return 0;
}
