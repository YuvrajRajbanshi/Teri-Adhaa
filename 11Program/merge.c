#include <stdio.h>

void merge(int a[], int l, int m, int h)
{
    int b[100], i, j, k;
    i = l, j = m + 1, k = l;

    while (i <= m && j <= h)
    {
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }

    while (i <= m)
        b[k++] = a[i++];
    while (j <= h)
        b[k++] = a[j++];

    for (i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[], int l, int h)
{
    int m;
    if (l < h)
    {
        m = (l + h) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

int main()
{
    int n, arr[100];
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    printf("\nEnter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n - 1);

    printf("\nSorted array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
