#include <stdio.h>
#define max 100
#define inf 999

int parent[max], cost[max][max];

int findRoot(int vertex)
{
    while (parent[vertex])
    {
        vertex = parent[vertex];
    }
    return vertex;
}

void uniosSets(int vertex1, int vertex2)
{
    vertex2 = parent[vertex1];
}

int kruskalMst(int numberOfvertices)
{
    int totalCost = 0, min, u, v, vertex1, vertex2;

    for (int j = 1; j < numberOfvertices; j++)
    {
        min = inf;
        for (int i = 1; i < numberOfvertices; i++)
        {
            for (int j = 1; j <= numberOfvertices; j++)
            {
                if (cost[i][j] < min)
                {
                    u = findRoot(i);
                    v = findRoot(j);

                    if (u != v)
                    {
                        vertex1 = i;
                        vertex2 = j;
                        min = cost[i][j];
                    }
                }
            }
        }

        uniosSets(findRoot(vertex1), findRoot(vertex2));
        totalCost += min;
    }
    printf("The total cost MST is %d", totalCost);
}
int main()
{
    int numberOfVertices;
    printf("\nEnter the number of vertices ");
    scanf("%d", &numberOfVertices);

    for (int i = 1; i <= numberOfVertices; i++)
    {
        for (int j = 1; j <= numberOfVertices; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskalMst(numberOfVertices);
    return 0;
}