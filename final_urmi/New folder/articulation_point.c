#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int disc[MAX], low[MAX], parent[MAX];
bool visited[MAX], isArticulationPoint[MAX];
int timeCounter = 0;

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int u, int n) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v, n);

                if (low[v] < low[u]) {
                    low[u] = low[v];
                }

                if (parent[u] == -1 && children > 1)
                    isArticulationPoint[u] = true;
                if (parent[u] != -1 && low[v] >= disc[u])
                    isArticulationPoint[u] = true;
            } else if (v != parent[u]) {
                if (disc[v] < low[u]) {
                    low[u] = disc[v];
                }
            }
        }
    }
}

void findArticulationPoints(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
        isArticulationPoint[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    printf("Articulation Points: ");
    for (int i = 0; i < n; i++) {
        if (isArticulationPoint[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n, e, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    findArticulationPoints(n);

    return 0;
}
