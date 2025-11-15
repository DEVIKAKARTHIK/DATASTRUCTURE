#include<stdio.h>
#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int queue[MAX];
int front = -1 ,rear = -1;
//queue operation

void enqueue(int value){
    if(rear == MAX-1) {
        printf("queue full");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int isEmpty(){
    if(front == -1 || front > rear) 
        return 1;
    return 0;
}

int dequeue() {
    if(isEmpty()) {
        printf("queue underflow\n");
        return -1;
    }
    return queue[front++];
}

void BFS(int start,int n){
    int current;
    enqueue(start);
    visited[start] =1;
    while(!isEmpty()) {
        current = dequeue();
        printf("%d",current);
        for(int i=0;i<n;i++){
            if(adj[current][i]==1 && visited[i]==0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n,e,u,v,start;
    printf("enter the no of vertices:\n");
    scanf("%d",&n);
     // init visited array

    for(int i=0;i<n;i++) {
        visited[i] = 0; 
    }

    //init matrix

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }
    printf("enter the no of edges \n");
    scanf("%d",&e);

    for(int i=0;i<e;i++){
        printf("enter the edge from u to v:\n");
        scanf("%d %d",&u,&v);
        adj[u][v] =1;
        adj[v][u] = 1; //delete this code if undirected graph
    }
    printf("enter the starting vertex:\n");
    scanf("%d",&start);
    printf("BFS traversal is:\n");
    BFS(start,n);
}