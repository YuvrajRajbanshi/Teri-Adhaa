#include <stdio.h>

#define INF 999 // Define infinity as a large value (999)
#define MAX 100 // Define the maximum number of vertices as 100

int parent[MAX], cost[MAX][MAX]; // Declare parent array, cost matrix, and result tree array

// Function to find the root of a vertex using path compression
int findRoot(int vertex)
{
    while (parent[vertex])
    {
        vertex = parent[vertex]; // Traverse to the root
    }
    return vertex; // Return the root
}

// Function to perform union of two subsets
void unionSets(int root1, int root2)
{
    parent[root2] = root1; // Make root1 as parent of root2
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(int numVertices)
{
    int i, j, k, u, v, min, vertex1, vertex2, totalCost = 0;

    for (k = 1; k < numVertices; k++)
    {
        min = INF; // Set initial minimum to infinity

        for (i = 1; i < numVertices; i++)
        {
            for (j = 1; j <= numVertices; j++)
            {
                if (i == j)
                {
                    continue; // Skip self-loops
                }

                if (cost[i][j] < min)
                {                    // If current edge is smaller than the minimum
                    u = findRoot(i); // Find root of i
                    v = findRoot(j); // Find root of j

                    if (u != v)
                    {                // If they are in different sets (no cycle)
                        vertex1 = i; // Store the vertices of the current edge
                        vertex2 = j;
                        min = cost[i][j]; // Update minimum edge
                    }
                }
            }
        }

        unionSets(findRoot(vertex1), findRoot(vertex2)); // Perform union of the sets
        totalCost += min;                                // Add the weight of the edge to the total cost
    }

    printf("\nCost of the spanning tree: %d\n", totalCost);
}

int main()
{
    int i, j, numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= numVertices; i++)
    {
        for (j = 1; j <= numVertices; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(numVertices);

    return 0;
}
