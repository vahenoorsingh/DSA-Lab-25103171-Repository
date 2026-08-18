#include <stdio.h>

int main()
{
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max_profit = 0;
    int min_price = arr[0];

    for (int i = 0; i < size; i++)
    {
        int profit = arr[i] - min_price;
        if (profit > max_profit)
        {
            max_profit = profit;
        }
        if (arr[i] < min_price)
            min_price = arr[i];
    }

    printf("Max Profit: %d", max_profit);
}