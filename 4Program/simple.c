#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int distance[MAX], visited[MAX];
    int i, j, minDistance, nextNode;

    // Initialize distances and visited nodes
    for (i = 0; i < n; i++)
    {
        distance[i] = graph[start][i];
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;

    // Find shortest path for all nodes
    for (i = 1; i < n; i++)
    {
        minDistance = INF;

        // Find the nearest unvisited node
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[j] < minDistance)
            {
                minDistance = distance[j];
                nextNode = j;
            }
        }

        // Mark the node as visited
        visited[nextNode] = 1;

        // Update distances of adjacent nodes
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && (minDistance + graph[nextNode][j] < distance[j]))
            {
                distance[j] = minDistance + graph[nextNode][j];
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances from node %d:\n", start);
    for (i = 0; i < n; i++)
    {
        printf("To node %d: %d\n", i, distance[i]);
    }
}

int main()
{
    int graph[MAX][MAX], n, start;
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the start node (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
