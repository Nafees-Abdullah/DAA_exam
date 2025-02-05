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

void BFS(int node) {
    int queue[10], front = 0, rear = 0;
    int i;

    printf("Visited vertex: %d\n", nodes[node][0]);
    nodes[node][1] = 1;
    queue[rear++] = node;

    while (front < rear) {
        int current_node = queue[front++];

        for (i = 0; i < num; i++) {
            if (adj_matrix[current_node][i] == 1 && nodes[i][1] == 0) {
                printf("Visited vertex: %d\n", nodes[i][0]);
                nodes[i][1] = 1;
                queue[rear++] = i;
            }
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

    BFS(0);

    return 0;
}