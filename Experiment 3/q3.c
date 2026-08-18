#include <stdio.h>

int main()
{
    int size;

    printf("Enter size: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int arr[size];
    int total_sum = 0;

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        total_sum += arr[i];
    }

    int leftsum = 0;
    int rightsum = total_sum;
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        rightsum -= arr[i];

        if (leftsum == rightsum)
        {
            printf("Equilibrium index: %d\n", i);
            found = 1;
        }

        leftsum += arr[i];
    }

    if (!found)
    {
        printf("No equilibrium index found.\n");
    }

    return 0;
}