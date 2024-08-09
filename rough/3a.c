#include <stdio.h>
#define max 10
int p[max][max];
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int floyd(int p[][max], int n)
{

    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}

int main()
{
    int n, arra[max][max];
    printf("Enter the size of array \n");
    scanf("%d", &n);

    printf("\nEnter the matrix ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arra[i][j]);
        }
    }

    floyd(arra, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", arra[i][j]);
        }
        printf("\n");
    }

    return 0;
}