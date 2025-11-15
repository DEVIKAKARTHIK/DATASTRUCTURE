#include<stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void DFS(int start,int n){
    printf("%d",start);
    visited[start] = 1;
    for(int i=0;i<n;i++) {
        if(adj[start][i]==1 && visited[i] == 0) {
            DFS(i,n);
        }
    }
}

int main()
{
    int n,e,u,v,start;
    printf("Enter the no of vertices:\n");
    scanf("%d",&n);

    //init visited array
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    //init adj matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }
    printf("enter the no of edges:\n");
    scanf("%d",&e);
    for(int i=0;i<e;i++) {
        printf("enter the edge from u to v\n");
        scanf("%d %d",&u,&v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    printf("enter the starting vertex:\n");
    scanf("%d",&start);
    printf("BFS starting is\n");
    DFS(start,n);
}