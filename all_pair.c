#include<stdio.h>
#define INF 99999
#define N 4
void floyd(int graph[N][N]){
    int dist[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dist[i][j]=graph[i][j];
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        printf("[");
        for(int j=0;j<N;j++){
            if(dist[i][j]==INF)
                printf("INF");
            else
                printf("%d",dist[i][j]);
            if(j<N-1)
            printf(", ");
        }
        
        printf("]");
        printf("\n");
    }
}
int main(){
    int graph[N][N]={
        {0,5,10,INF},
        {INF,0,3,9},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };
    floyd(graph);
    return 0;
}
