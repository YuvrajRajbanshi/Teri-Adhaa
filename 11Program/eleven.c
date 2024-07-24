#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two sorted arrays
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to generate random integers
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000; // Generate random integers between 0 and 99999
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 5000)
    {
        printf("Please enter a value greater than 5000\n");
        return 1; // Exit if the number of elements is not greater than 5000
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    generateRandomArray(arr, n);

    // Repeat the sorting process multiple times to increase duration for timing
    clock_t start = clock();
    for (int i = 0; i < 1000; i++)
    {
        mergeSort(arr, 0, n - 1);
    }
    clock_t end = clock();

    // Calculate the time taken for one iteration
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}

// import matplotlib.pyplot as plt

// # data collected (replace with actual data)
// n_values = [6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 15000]
// time_taken = [0.000709, 0.000752, 0.000916, 0.001493, 0.001589, 0.002562, 0.001944, 0.002961, 0.003563]  # Replace with actual times recorded

// plt.plot(n_values, time_taken, marker='o')
// plt.title('Merge Sort Time Complexity')
// plt.xlabel('Number of Elements (n)')
// plt.ylabel('Time taken (seconds)')
// plt.grid(True)
// plt.show()

// Enter number of elements: 6000
// Time taken to sort 6000 elements: 0.000709 seconds

// ********************************************************************

// Enter number of elements: 7000
// Time taken to sort 7000 elements: 0.000752 seconds

// ********************************************************************

// Enter number of elements: 8000
// Time taken to sort 8000 elements: 0.000916 seconds

// ********************************************************************

// Enter number of elements: 9000
// Time taken to sort 9000 elements: 0.001493 seconds

// ********************************************************************

// Enter number of elements: 10000
// Time taken to sort 10000 elements: 0.001589 seconds

// ********************************************************************

// Enter number of elements: 11000
// Time taken to sort 11000 elements:  0.002562 seconds

// ********************************************************************

// Enter number of elements: 12000
// Time taken to sort 12000 elements: 0.001944 seconds

// ********************************************************************

// Enter number of elements: 13000
// Time taken to sort 13000 elements: 0.002961 seconds

// ********************************************************************

// Enter number of elements: 15000
// Time taken to sort 15000 elements: 0.003563 seconds