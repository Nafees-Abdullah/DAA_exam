#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX], n, e;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_sets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void sort_edges() {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal() {
    int mst_weight = 0;
    printf("\nEdges in MST:\n");
    for (int i = 0; i < e; i++) {
        int u_set = find(edges[i].u);
        int v_set = find(edges[i].v);
        if (u_set != v_set) {
            printf("(%d, %d) -> %d\n", edges[i].u, edges[i].v, edges[i].weight);
            mst_weight += edges[i].weight;
            union_sets(u_set, v_set);
        }
    }
    printf("\nTotal cost of MST: %d\n", mst_weight);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort_edges();
    kruskal();

    return 0;
}
