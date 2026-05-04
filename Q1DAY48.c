#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX];   // adjacency matrix
int degree[MAX];     // degree of each node

int main() {
    int n;
    scanf("%d", &n);

    // initialize
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // read edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // assuming nodes are 0-based
        adj[u][v] = adj[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }

    int leafCount = 0;

    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            leafCount++;
        }
    }

    printf("%d\n", leafCount);

    return 0;
}