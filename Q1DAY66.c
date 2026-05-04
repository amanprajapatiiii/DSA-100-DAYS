#include <stdio.h>
#include <stdbool.h>

#define V 100 
int graph[V][V];
int vertices;


bool dfs(int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i]) {
            
            if (!visited[i] && dfs(i, visited, recStack))
                return true;
            
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false; 
    return false;
}

bool hasCycle() {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
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

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}