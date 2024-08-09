#include <stdio.h>

int a[10][10], n, indegree[10];
void find_degree()
{
    int i, j, sum;
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum = sum + a[i][j];

        indegree[j] = sum;
    }
}
void topo()
{

    int i, u, v, t[10], s[10], top = -1, k = 0;
    find_degree();

    for (i = 0; i < n; i++)
    {

        if (indegree[i] == 0)
            s[++top] = i;
    }

    while (top != 1)
    {

        u = s[top--];
        t[i++] = u;
        for (v = 0; v < n; v++)
        {

            if (a[u][v] == 1)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    s[++top] = v;
            }
        }
    }

    printf("\nTopological Ordering :\n");

    for (i = 0; i < n; i++)
        printf("%d\t", t[i]);
}

int main()
{

    int i, j;
    printf("\nEnter number of node: ");
    scanf("%d", &n);
    printf("\nEnter the adjacent matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    topo();

    return 0;
}