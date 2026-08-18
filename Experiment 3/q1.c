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

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = size - 1;
    int left_max = 0;
    int right_max = 0;
    int total_trapped = 0;

    while (left < right)
    {
        if (arr[left] < arr[right])
        {
            if (arr[left] >= left_max)
            {
                left_max = arr[left];
            }
            else
            {
                total_trapped += left_max - arr[left];
            }
            left++;
        }
        else
        {
            if (arr[right] >= right_max)
            {
                right_max = arr[right];
            }
            else
            {
                total_trapped += right_max - arr[right];
            }
            right--;
        }
    }

    printf("Total Water Trapped is: %d\n", total_trapped);
    return 0;
}