#include<stdio.h>
#include<stdlib.h>
void dfs(int s);
int graph[20][20], visited[20], total, arr[20];
static int k=0,count=0;
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
    printf("\nAFTER BFS:\n");
    dfs(s);
}
void dfs(int s)
{
    int j,k,c=0;
    count++;
    printf("%d  ",s);
    visited[s]=1;

    for(k=0; k<total; k++)
    {
        if (!visited[k] && graph[s][k]==1)
        {
            arr[++k]=j;
            c=1;
        }
        if (count == total)
        {
            exit(0);
        }
        if(count==1)
        {
            dfs(arr[k]);
        }
        else
        {
            k--;
            dfs(arr[k]);

        }
    }
}
