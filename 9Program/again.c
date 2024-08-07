#include <stdio.h>

void selection(int arr[], int n)
{
    int i, j;
    int min = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {

            if (arr[min] > arr[j])
            {
                min = j;
            }

            // swapping

            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int n, arr[500];
    printf("\nEnter the size of the array");
    scanf("%d", &n);

    printf("\nEnter the array elements");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nAfter sorting element ");
    selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}