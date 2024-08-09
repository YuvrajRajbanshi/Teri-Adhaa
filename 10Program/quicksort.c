#include <stdio.h>
#include <time.h>

int partition(int arr[], int low, int high);
int quick(int arr[], int low, int high);
int main()
{

    int n, arr[100];
    time_t first, second;

    first = time(NULL);
    printf("Enter the size of array \n");
    scanf("%d", &n);

    printf("\nEnter the array elements ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quick(arr, 0, n - 1);

    printf("\nThe sorted elements are here \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    second = time(NULL);

    printf("Total taken %f ", difftime(second, first));

    return 0;
}
int quick(int arr[], int low, int high)
{
    if (low < high)
    {

        int pivot = partition(arr, low, high);
        quick(arr, low, pivot - 1);
        quick(arr, pivot + 1, high);
    }
}
int partition(int arr[], int low, int high)
{
    int i = (low - 1);
    int pivot = arr[high];

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[i] < pivot)
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
