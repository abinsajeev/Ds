#include <stdio.h>

#define MAX 100 
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = v;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;  
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}


void bfs(int graph[MAX][MAX], int visited[MAX], int start, int vertices) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int i;
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}


int main() {
    int vertices, start;
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix (%d x %d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 - %d): ", vertices - 1);
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(graph, visited, start, vertices);

    printf("\n");
    return 0;
}
