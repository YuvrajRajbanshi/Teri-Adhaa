#include <stdio.h>
#define inf 999
#define max 10
int parent[max], cost[max][max];

int findRoot(int vertex)
{

    while (parent[vertex])
    {
        vertex = parent[vertex];
    }
    return vertex;
}

int unions(int vertex1, int vertex2)
{
    vertex2 = parent[vertex2];
}

int kruskal(int numberOfvertices)
{
    int min, u, v, vertex1, vertex2, minDis;
    for (int j = 0; j < numberOfvertices; j++)
    {
        min = inf;
        for (int j = 0; j < numberOfvertices; j++)
        {
            for (int i = 0; i <= numberOfvertices; i++)
            {
                if (cost[i][j] < min)
                {
                    u = findRoot(i);
                    v = findRoot(j);
                }
                if (u != v)
                {
                    vertex1 = i;
                    vertex2 = j;
                    minDis = cost[i][j];
                }
            }
        }
    }
}
int main()
{

    return 0;
}