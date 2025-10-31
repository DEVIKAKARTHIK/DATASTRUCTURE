#include <stdio.h>

#define MAX 100  // Maximum number of vertices

int stack[MAX];   // Stack array
int top = -1;     // Stack pointer

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array
int n;              // Number of vertices

// Push function to add element to stack
void push(int vertex) {
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = vertex;
}

// Pop function to remove top element from stack
int pop() {
    if (top == -1)
        return -1; // Stack empty
    else
        return stack[top--];
}

// DFS using stack (iterative)
void dfs_iterative(int start) {
    int i, vertex;

    push(start);             // Push starting vertex
    visited[start] = 1;      // Mark it as visited

    while (top != -1) {      // While stack is not empty
        vertex = pop();      // Pop the top vertex
        printf("%d ", vertex);

        // Check neighbors from last to first
        // (so that smaller numbered vertices are visited first)
        for (i = n - 1; i >= 0; i--) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;  // Initialize all vertices as unvisited

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS Traversal (using stack) starting from vertex %d:\n", start);
    dfs_iterative(start);

    return 0;
}
