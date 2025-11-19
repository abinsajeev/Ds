#include <stdio.h>
#define MAX 10
int STACK [MAX], top=-1;

void push(int v)
{
    if (top==MAX-1)
        printf("Stack Overflow");
    else {
        STACK[++top]=v;
    }
}

int pop()
{
    if (top==-1)
        return -1;
    return STACK[top--];

}

void dfs(int adj[MAX][MAX],int visited[MAX], int start, int vertices) {

    push(start);
    visited[start] = 1;

    while (top != -1) {
        int current = pop();  
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {  
                push(i); 
                visited[i] = 1;
            }
        }
    }

}
void main() {

     int n, e, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int visited[MAX]={0};
    int adj[MAX][MAX]={0}; 

    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printf("Enter starting vertex (0 - %d): ", n-1);
    scanf("%d", &start);
    printf("DFS Traversal: ");
    dfs(adj,visited,start, n);
    printf("\n");

}