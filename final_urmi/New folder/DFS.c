#include <stdio.h>
int adj_matrix[10][10], nodes[10][2], num;

void input_adj() {
    int i, j;
    for(i = 0; i < num; i++) {
        for(j = 0; j < num; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
}

void DFS(int node) {
    int x;
    printf("vertice: %d\t", nodes[node][0]);
    nodes[node][1] = 1;
    for(x = 0; x < num; x++) {
        if(nodes[x][1] == 0 && adj_matrix[node][x] == 1) {
            DFS(x);
        }
    }
}

int main() {
    int i;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    printf("Enter the vertices of the graph:\n");
    for(i = 0; i < num; i++) {
        scanf("%d", &nodes[i][0]);
    }
    for(i = 0; i < num; i++) {
        nodes[i][1] = 0;
    }
    for(i = 0; i < num; i++) {
        printf("%d ", nodes[i][0]);
    }

    printf("\nEnter the adjacency matrix of the graph:\n");
    input_adj();

    DFS(0);

    return 0;
}