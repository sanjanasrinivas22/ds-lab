#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

void dfs(int graph[MAX][MAX], int node, bool visited[MAX], int n) {
    visited[node] = true;
    printf("%d ", node);
    
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, i, visited, n);
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
    
    bool visited[MAX] = {false};
    
    printf("DFS Traversal starting from node %d: ", start);
    dfs(graph, start, visited, n);
    printf("\n");
    
    return 0;
}
