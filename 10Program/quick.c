#include <stdio.h>
#include <time.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void main()
{
    time_t first, second;
    int i, n, a[15];

    printf("\nQuick sort timing analysis \n");

    first = time(NULL);

    printf("\nEnter unsorted array size :");
    scanf("%d", &n);

    printf("\nEnter array elements \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("\nArray elements after sorting : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    second = time(NULL);
    printf("The Difference is %f seconds \n", difftime(second, first));
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
