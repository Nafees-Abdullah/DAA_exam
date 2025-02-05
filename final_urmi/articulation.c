#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX], discovery[MAX], low[MAX], parent[MAX], timeCounter;
bool visited[MAX], isArticulation[MAX];

void dfs(int u, int vertices) {
    visited[u] = true;
    discovery[u] = low[u] = ++timeCounter;

    int children = 0;
    for (int v = 0; v < vertices; v++) {
        if (adj[u][v]) { // Check if there's an edge
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v, vertices);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                // Articulation point conditions
                if (parent[u] == -1 && children > 1) isArticulation[u] = true;
                if (parent[u] != -1 && low[v] >= discovery[u]) isArticulation[u] = true;
            } else if (v != parent[u]) {
                low[u] = (low[u] < discovery[v]) ? low[u] : discovery[v];
            }
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0; // Initialize adjacency matrix
        }
        visited[i] = isArticulation[i] = false;
        parent[i] = -1;
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // Add edge
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) dfs(i, vertices);
    }

    printf("Articulation Points:\n");
    for (int i = 0; i < vertices; i++) {
        if (isArticulation[i]) printf("%d ", i);
    }

    return 0;
}

