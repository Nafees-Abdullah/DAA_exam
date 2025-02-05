#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int reverseGraph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int stack[MAX_NODES], top = -1;
int nodes;

void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < nodes; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs1(i);
        }
    }
    stack[++top] = v;
}

void dfs2(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < nodes; i++) {
        if (reverseGraph[v][i] && !visited[i]) {
            dfs2(i);
        }
    }
}

void component() {
    int count = 0;

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            reverseGraph[i][j] = graph[j][i];
        }
        visited[i] = 0;
    }

    printf("Strongly Connected Components:\n");
    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            printf("component %d = ", ++count);
            dfs2(v);
            printf("\n");
        }
    }

    printf("Total number of Strongly Connected Components: %d\n", count);
}

int main() {
    int edges, u, v;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (u v) for each edge:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    component();

    return 0;
}
