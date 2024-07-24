#include <stdio.h>

// kruskal algorithm
#define INF 999 // Define infinity as a large value (999)
#define MAX 100 // Define the maximum number of vertices as 100

int p[MAX], c[MAX][MAX], t[MAX][2]; // Declare parent array, cost matrix, and result tree array

// Function to find the root of a vertex using path compression
int find(int v)
{
    while (p[v])
        v = p[v]; // Traverse to the root
    return v;     // Return the root
}

// Function to perform union of two subsets
void union1(int i, int j)
{
    p[j] = i; // Make i as parent of j
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(int n)
{
    int i, j, k, u, v, min, res1, res2, sum = 0; // Initialize variables
    for (k = 1; k < n; k++)                      // Loop to select n-1 edges
    {
        min = INF;                  // Set initial minimum to infinity
        for (i = 1; i < n - 1; i++) // Loop through the cost matrix
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;      // Skip self-loops
                if (c[i][j] < min) // If current edge is smaller than the minimum
                {
                    u = find(i); // Find root of i
                    v = find(j); // Find root of j
                    if (u != v)  // If they are in different sets (no cycle)
                    {
                        res1 = i; // Store the vertices of the current edge
                        res2 = j;
                        min = c[i][j]; // Update minimum edge
                    }
                }
            }
        }
        union1(res1, find(res2)); // Perform union of the sets
        t[k][1] = res1;           // Store the edge in the result array
        t[k][2] = res2;
        sum = sum + min; // Add the weight of the edge to the total cost
    }
    printf("\nCost of spanning tree is=%d", sum); // Print the total cost
    printf("\nEdges of spanning tree are:\n");
    for (i = 1; i < n; i++) // Loop through the result array to print the edges
        printf("%d -> %d\n", t[i][1], t[i][2]);
}

int main()
{
    int i, j, n;                    // Declare variables
    printf("\nEnter the n value:"); // Prompt for number of vertices
    scanf("%d", &n);                // Read the number of vertices
    for (i = 1; i <= n; i++)
        p[i] = 0;                        // Initialize the parent array to 0
    printf("\nEnter the graph data:\n"); // Prompt for graph data
    for (i = 1; i <= n; i++)             // Loop to read the cost adjacency matrix
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]); //
    kruskal(n);
    return 0;
}
// Enter the n value:5

// Enter the graph data:
// 1 3 4 6 2
// 1 7 6 9 3
// 5 2 8 99 45
// 1 44 66 33 6
// 12 4 3 2 0

// Cost of spanning tree is=11
// Edgesof spanning tree are:
// 2 -> 1
// 1 -> 5
// 3 -> 2
// 1 -> 4