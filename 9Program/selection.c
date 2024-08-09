#include <stdio.h>
#include <time.h>
void section(int arr[], int n)
{
    int temp;
    int min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[20], n;
    time_t first, second;
    first = time(NULL);
    printf("\nEnter the size of array\n");
    scanf("%d", &n);

    printf("Enter the array elements \n");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }

    section(arr, n);
    printf("\nThe sorted elements are.........\n");

    for (int j = 0; j < n; j++)
    {
        printf("%d", arr[j]);
    }

    second = time(NULL);

    printf("The time consuming by cput for selection sort is %f", difftime(second, first));
    return 0;
}