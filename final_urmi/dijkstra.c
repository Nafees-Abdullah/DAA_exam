#include <stdio.h>
#include <limits.h>
#define MAX 100

void dijkstra(int g[MAX][MAX], int v, int src)
{
    int d[v], vis[v], i, j, u;
    for (i = 0; i < v; i++)
    {
        d[i] = INT_MAX;
        vis[i] = 0;
    }
    d[src] = 0;

    for (i = 0; i < v - 1; i++)
    {
        int min = INT_MAX;
        for (j = 0; j < v; j++)
        {
            if (!vis[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }

        }
        vis[u] = 1;
        for (j = 0; j < v; j++)
        {
            if (!vis[j] && g[u][j] && d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
        }
    }
int sum=0;
    for (i = 0; i < v; i++)
    {
        printf("Node %d: %d\n", i, d[i]);
        sum=sum+d[i];
    }
    printf("total = %d",sum);
}

int main()
{
    int v, g[MAX][MAX], src;
    printf("Vertices: ");
    scanf("%d", &v);

    printf("Graph:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            scanf("%d", &g[i][j]);
    }
    printf("Source: ");
    scanf("%d", &src);
    dijkstra(g, v, src);
    return 0;
}

