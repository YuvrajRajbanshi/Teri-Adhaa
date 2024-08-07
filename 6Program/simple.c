#include <stdio.h>

#define MAX_ITEMS 10

int weights[MAX_ITEMS], profits[MAX_ITEMS], numItems;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int currentIndex, int remainingCapacity)
{
    if (currentIndex == numItems)
    {
        return (weights[currentIndex] > remainingCapacity) ? 0 : profits[currentIndex];
    }
    if (weights[currentIndex] > remainingCapacity)
    {
        return knapsack(currentIndex + 1, remainingCapacity);
    }
    return max(knapsack(currentIndex + 1, remainingCapacity),
               knapsack(currentIndex + 1, remainingCapacity - weights[currentIndex]) + profits[currentIndex]);
}

int main()
{
    int capacity, maxProfit;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("Item %d - Profit: ", i + 1);
        scanf("%d", &profits[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
    }

    maxProfit = knapsack(0, capacity);
    printf("Maximum profit = %d\n", maxProfit);

    return 0;
}
