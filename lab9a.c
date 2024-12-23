#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void bfs(int graph[MAX][MAX], int start, int n) {
    bool visited[MAX] = {false};
    struct Queue q;
    initQueue(&q);
    
    visited[start] = true;
    enqueue(&q, start);
    
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int n, start;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    int graph[MAX][MAX] = {0};
    
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the starting node: ");
    scanf("%d", &start);
    
    printf("BFS Traversal starting from node %d: ", start);
    bfs(graph, start, n);
    printf("\n");
    
    return 0;
}
