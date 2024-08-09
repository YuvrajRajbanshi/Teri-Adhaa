#include <stdio.h>
#define INF 999 // Define a large value to represent infinity

// Function to implement Prim's algorithm
int prim(int cost[10][10], int numVertices, int startVertex)
{
    int visited[10], i, j, totalCost = 0;
    int vertex[10], distance[10], minDistance, nextVertex;

    // Initialize arrays
    for (i = 1; i <= numVertices; i++)
    {
        vertex[i] = startVertex;            // Initialize all vertices to the start vertex
        distance[i] = cost[startVertex][i]; // Initialize distances from the start vertex
        visited[i] = 0;                     // Mark all vertices as unvisited
    }
    visited[startVertex] = 1; // Mark the start vertex as visited

    // Loop to find the minimum spanning tree
    for (i = 1; i < numVertices; i++)
    {
        minDistance = INF;

        // Find the nearest unvisited vertex
        for (j = 1; j <= numVertices; j++)
        {
            if (!visited[j] && distance[j] < minDistance)
            {
                minDistance = distance[j];
                nextVertex = j;
            }
        }

        visited[nextVertex] = 1;           // Mark the selected vertex as visited
        totalCost += distance[nextVertex]; // Add its distance to the total cost

        // Print the edge selected
        printf("\n%d -> %d, Current total cost = %d", vertex[nextVertex], nextVertex, totalCost);

        // Update the distances of the adjacent vertices
        for (j = 1; j <= numVertices; j++)
        {
            if (!visited[j] && cost[nextVertex][j] < distance[j])
            {
                distance[j] = cost[nextVertex][j];
                vertex[j] = nextVertex;
            }
        }
    }

    return totalCost;
}

int main()
{
    int cost[10][10], i, j, result, startVertex, numVertices;

    // Input the number of vertices
    printf("\nEnter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input the graph as a cost adjacency matrix
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= numVertices; i++)
    {
        for (j = 1; j <= numVertices; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Input the starting vertex
    printf("\nEnter the starting vertex: ");
    scanf("%d", &startVertex);

    // Call Prim's algorithm and print the result
    result = prim(cost, numVertices, startVertex);
    printf("\nTotal cost of the minimum spanning tree: %d\n", result);

    return 0;
}
