#include <stdio.h>
#define inf 999
#define max 10

int dijkAlgo(int graph[max][max], int start, int n)
{
    // initialize the code
    int distance[max], i, j, visited[max], minDistance, nextNode;

    for (i = 0; i < n; i++)
    {
        distance[i] = graph[start][i];
        visited[i] = 0;
    }

    distance[start] = 0; // Mark the starting node distance as 0 (Added comment)
    visited[start] = 1;  // Mark the start node as visited (Added comment)

    // find minimum distance between vertices
    for (i = 1; i < n; i++)
    {
        minDistance = inf;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[j] < minDistance)
            {
                minDistance = distance[j];
                nextNode = j;
            }
        }
        visited[nextNode] = 1; // Mark nextNode as visited (Added comment)

        // adjacency matrix ko dhundo yar bada dhukh hua sunkar
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && minDistance + graph[nextNode][j] < distance[j])
            {
                distance[j] = minDistance + graph[nextNode][j];
            }
        }
    }

    // Print the shortest distance from the start node to each vertex (Reworded comment)
    printf("\nShortest distance from source node %d ", start);
    for (int i = 0; i < n; i++)
    {
        printf("To node %d: %d\n", i, distance[i]);
    }
}

int main()
{
    int n, graph[max][max], source;

    printf("\nEnter the number of vertices: "); // Reworded prompt message
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n"); // Simplified prompt message
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter the starting node (0 to %d): ", n - 1); // Reworded prompt message
    scanf("%d", &source);

    dijkAlgo(graph, source, n); // Removed extra empty line before function call

    return 0;
}
