#include<stdio.h>
#include<limits.h>
#define MAX 100
int minDis(int dist[],int visit[],int n)
{
    int min=INT_MAX,min_index;
    for(int v=0;v<n;v++)
    {
        if(visit[v]==0&&dist[v]<=min)
        {
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX],int n,int src,int dest)
{
    int dist[MAX],visit[MAX]={0};
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int count=0;count<n-1;count++)
    {
        int u=minDis(dist,visit,n);
        visit[u]=1;
        for(int v=0;v<n;v++)
        {
            if(!visit[v]&&graph[u][v]&&dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("Shortest time for headquaters (City %d) to City %d:%d milliseconds\n",src+1,dest+1,dist[dest]);
}
int main()
{
    int n,e;
    printf("Enter the no of cities: ");
    scanf("%d",&n);
    int graph[MAX][MAX]={0};
    printf("Enter the no of connections Between Cities: ");
    scanf("%d",&e);
    printf("Enter the connections in the format (C1 c2 time):\n");
    for(int i=0;i<e;i++)
    {
        int u,v,time;
        scanf("%d %d %d",&u,&v,&time);
        u--;
        v--;
        graph[u][v]=time;
        graph[v][u]=time;
    }
    int src,dest;
    printf("Emter the Source city:");
    scanf("%d",&src);
    printf("Enter the destenation city: ");
    scanf("%d",&dest);
    src--;
    dest--;
    dijkstra(graph,n,src,dest);
    return 0;
}




