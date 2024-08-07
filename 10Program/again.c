#include <stdio.h>

int quickSort(int arr[], int high, int low);
int partinition(int arr[], int high, int low);

int main()
{

    return 0;
}

int quickSort(int arr[], int high, int low)
{

    int mid = low + (high - low) / 2;
    if (low >= high)
    {
        return;
    }
    int indx = partinition(arr, high, low);
    quickSort(arr, low, indx - 1);
    quickSort(arr, indx + 1, high);
}

int partinition(int arr[], int high, int low)
{
    int i = low - 1;
    int pivot = arr[high];

    for (int j = 0; j < high; j++)
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