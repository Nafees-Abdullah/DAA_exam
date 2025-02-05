#include<stdio.h>
void dfs(int s);
int graph[20][20], visited[20], total;
int main()
{
    int i,s,j;
    printf("number of vertices=");
    scanf("%d",&total);

    printf("\n enter matrix=\n");
    for(i=0; i<total; i++)
    {
        for(j=0; j<total; j++)
        {
            scanf("%d",&graph[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<total; i++)
    {
        visited[i]=0;
    }

    printf("\nstarting node=");
    scanf("%d",&s);
    printf("\nAFTER DFS:\n");
    dfs(s);
}
void dfs (int s)
{
    int k;
    printf("%d  ",s);
    visited[s]=1;

    for(k=0; k<total; k++)
    {
        if (!visited[k] && graph[s][k]==1)
        {
            dfs(k);

        }
    }

}
