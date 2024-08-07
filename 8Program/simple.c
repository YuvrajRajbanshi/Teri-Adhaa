#include <stdio.h>

#define MAX 10

int set[MAX], included[MAX], targetSum;

void findSubsetSum(int currentSum, int currentIndex, int remainingSum)
{
    if (currentSum == targetSum)
    {
        // Print the current subset
        for (int i = 0; i < currentIndex; i++)
        {
            if (included[i])
            {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
        return;
    }

    if (currentIndex >= MAX || currentSum > targetSum)
    {
        return;
    }

    // Include the current element
    included[currentIndex] = 1;
    if (currentSum + set[currentIndex] <= targetSum)
    {
        findSubsetSum(currentSum + set[currentIndex], currentIndex + 1, remainingSum - set[currentIndex]);
    }

    // Exclude the current element
    included[currentIndex] = 0;
    if (currentSum + remainingSum - set[currentIndex] >= targetSum)
    {
        findSubsetSum(currentSum, currentIndex + 1, remainingSum - set[currentIndex]);
    }
}

int main()
{
    int numElements, totalSum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    printf("Enter the elements in increasing order:\n");
    for (int i = 0; i < numElements; i++)
    {
        scanf("%d", &set[i]);
        totalSum += set[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    if (totalSum < targetSum || set[0] > targetSum)
    {
        printf("No subset possible\n");
    }
    else
    {
        findSubsetSum(0, 0, totalSum);
    }

    return 0;
}
