#include <stdio.h>

#define MAX_NODES 10

void displayDegrees(int graph[MAX_NODES][MAX_NODES], int n) {
    int inDegree[MAX_NODES] = {0};
    int outDegree[MAX_NODES] = {0};

    // Calculate in-degree and out-degree for each node
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }

    // Display the degrees
    printf("Node\tIn-Degree\tOut-Degree\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i, inDegree[i], outDegree[i]);
    }
}

int main() {
    int n, graph[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    displayDegrees(graph, n);
    return 0;
}
