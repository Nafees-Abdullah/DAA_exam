#include <stdio.h>

int graph[20][20], visited[20];
int queue[20], front = 0, rear = -1;
int total;

void bfs(int start) {
    int i;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS traversal: ");

    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);


        for (i = 0; i < total; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, start;

    printf("Number of vertices: ");
    scanf("%d", &total);

    printf("\nEnter adjacency matrix:\n");
    for (i = 0; i < total; i++) {
        for (j = 0; j < total; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Starting node: ");
    scanf("%d", &start);

    for (i = 0; i < total; i++) {
        visited[i] = 0;
    }

    printf("AFTER BFS:\n");
    bfs(start);

    return 0;
}
