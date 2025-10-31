#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices in the graph

int queue[MAX];   // Array to implement queue
int front = -1, rear = -1;  // Queue pointers

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Function to remove an element from the queue
int dequeue() {
    int vertex;
    if (front == -1 || front > rear)
        return -1; // Queue empty
    vertex = queue[front];
    front++;
    return vertex;
}

// BFS function
void bfs(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int i, current;

    enqueue(start);        // Start BFS from the starting node
    visited[start] = 1;    // Mark start node as visited

    while (front <= rear) {    // Run until queue becomes empty
        current = dequeue();   // Take one vertex from queue
        printf("%d ", current); // Print it (this is the BFS traversal order)

        // Check all neighbors of the current vertex
        for (i = 0; i < n; i++) {
            // If there is an edge and vertex is not visited
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1; // Mark as visited
            }
        }
    }
}

int main() {
    int n, adj[MAX][MAX], visited[MAX] = {0};
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS Traversal starting from vertex %d:\n", start);
    bfs(adj, visited, start, n);

    return 0;
}
