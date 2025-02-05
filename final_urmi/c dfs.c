#include <stdio.h>

void dfs(int s);
int graph[20][20], visited[20], total;

int main() {
    int i, j, s;

    printf("Number of vertices: ");
    scanf("%d", &total);

    printf("\nEnter adjacency matrix:\n");
    for (i = 0; i < total; i++) {
        for (j = 0; j < total; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize all nodes as unvisited
    for (i = 0; i < total; i++) {
        visited[i] = 0;
    }

    printf("\nStarting node: ");
    scanf("%d", &s);

    printf("\nDFS traversal starting from node %d:\n", s);
    dfs(s);

    return 0;
}

void dfs(int s) {
    int k;
    printf("%d ", s); // Print the current node
    visited[s] = 1;   // Mark this node as visited

    // Recursively visit all adjacent unvisited nodes
    for (k = 0; k < total; k++) {
        if (!visited[k] && graph[s][k] == 1) {
            dfs(k);
        }
    }
}

