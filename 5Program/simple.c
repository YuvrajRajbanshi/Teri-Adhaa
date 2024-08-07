#include <stdio.h>

int topOrder[10], orderIndex = 0;
void topologicalSort(int graph[][10], int inDegree[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            inDegree[i] = -1;           // Mark as visited
            topOrder[orderIndex++] = i; // Add to topological order
            // Decrease the in-degree of neighboring nodes
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] == 1)
                {
                    inDegree[j]--;
                }
            }
            // Restart the loop to account for changes in in-degrees
            i = -1;
        }
    }
}

int main()
{
    int graph[10][10], inDegree[10], n;
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize in-degrees to 0
    for (i = 0; i < n; i++)
    {
        inDegree[i] = 0;
    }

    // Read the graph data and compute in-degrees
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1)
            {
                inDegree[j]++;
            }
        }
    }

    topologicalSort(graph, inDegree, n);

    // Check if topological sorting is possible
    if (orderIndex != n)
    {
        printf("Topological ordering not possible (cycle detected).\n");
    }
    else
    {
        printf("Topological ordering is: ");
        for (i = 0; i < orderIndex; i++)
        {
            printf("%d ", topOrder[i]);
        }
        printf("\n");
    }

    return 0;
}
