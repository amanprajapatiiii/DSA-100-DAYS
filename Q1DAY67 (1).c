#include <stdio.h>
#include <stdbool.h>

#define V 100

int graph[V][V];
int vertices;

int stack[V];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void dfs(int node, bool visited[]) {
    visited[node] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, visited);
        }
    }

    push(node);
}

void topologicalSort() {
    bool visited[V] = {false};

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int edges;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}