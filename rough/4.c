#include <stdio.h>
#define max 10
#define inf 999

void dikhsaAlgo(int graph[max][max], int n, int start)
{

    int visited[max], cost[max][max], distance[max], min, nextNode;
    // initialization
    for (int j = 0; j < n; j++)

    {
        distance[j] = graph[start][j];
        visited[j] = 0;
    }
    visited[start] = 1;
    distance[start] = 0;

    // finding minimum distance

    for (int i = 0; i < n; i++)
    {
        min = inf;

        for (int j = 1; j < n; j++)
        {

            if (!visited[j] && distance[j] < min)
            {
                min = distance[j];
                nextNode = j;
            }
        }

        visited[nextNode] = 1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (min + cost[nextNode][j]) < distance[j])
            {
                distance[j] = min + cost[nextNode][j];
            }
        }
    }
}
int main()
{

    return 0;
}