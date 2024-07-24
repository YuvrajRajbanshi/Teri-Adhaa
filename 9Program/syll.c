#include <stdio.h>
#include <time.h>

void main()
{
    time_t first, second;
    int i, j, min, n, a[15], temp;

    printf("\nSelection sort timing analysis \n");

    first = time(NULL);

    printf("\nEnter unsorted array size :");
    scanf("%d", &n);

    printf("\nEnter array elements \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("\nArray elements after sorting : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    second = time(NULL);
    printf("The Difference is %f seconds \n", difftime(second, first));
}
