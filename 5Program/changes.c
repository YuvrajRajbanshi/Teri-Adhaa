#include <stdio.h>

int adjacencyMatrix[10][10], numberOfNodes, inDegree[10];

void calculateInDegree()
{
    int i, j;
    for (j = 0; j < numberOfNodes; j++)
    {
        inDegree[j] = 0; // Initialize inDegree for each node
        for (i = 0; i < numberOfNodes; i++)
        {
            inDegree[j] += adjacencyMatrix[i][j]; // Calculate in-degree by summing up the column
        }
    }
}

void topologicalSort()
{
    int i, u, v, sortedOrder[10], stack[10], top = -1, sortedIndex = 0;

    calculateInDegree(); // Calculate in-degree for each node

    // Push nodes with 0 in-degree onto the stack
    for (i = 0; i < numberOfNodes; i++)
    {
        if (inDegree[i] == 0)
        {
            stack[++top] = i; // Push the node onto the stack
        }
    }

    // Perform topological sorting
    while (top != -1) // While the stack is not empty
    {
        u = stack[top--];               // Pop a node from the stack
        sortedOrder[sortedIndex++] = u; // Add the node to the sorted order

        for (v = 0; v < numberOfNodes; v++)
        {
            if (adjacencyMatrix[u][v] == 1) // If there is an edge from u to v
            {
                inDegree[v]--; // Decrease the in-degree of node v
                if (inDegree[v] == 0)
                {
                    stack[++top] = v; // If in-degree becomes 0, push it onto the stack
                }
            }
        }
    }

    // Print the topological order
    printf("\nTopological Ordering:\n");
    for (i = 0; i < sortedIndex; i++)
    {
        printf("%d\t", sortedOrder[i]);
    }
}

int main()
{
    int i, j;
    printf("\nEnter number of nodes: ");
    scanf("%d", &numberOfNodes);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < numberOfNodes; i++)
    {
        for (j = 0; j < numberOfNodes; j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
