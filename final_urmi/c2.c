#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX];
int total;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < total; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int start;

    printf("Enter the number of vertices: ");
    scanf("%d", &total);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize all vertices as unvisited
    for (int i = 0; i < total; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("DFS traversal starting from node %d:\n", start);
    dfs(start);

    return 0;
}

