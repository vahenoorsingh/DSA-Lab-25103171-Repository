#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (size == 1)
    {
        printf("No second largest or smallest exist because size is 1\n");
        free(arr);
        return 0;
    }

    int l1, l2, s1, s2;

    if (arr[0] < arr[1])
    {
        l1 = arr[1];
        l2 = arr[0];
        s1 = arr[0];
        s2 = arr[1];
    }
    else
    {
        l1 = arr[0];
        l2 = arr[1];
        s1 = arr[1];
        s2 = arr[0];
    }

    for (int i = 2; i < size; i++)
    {
        // Find second largest
        if (arr[i] > l1)
        {
            l2 = l1;
            l1 = arr[i];
        }
        else if (l1 != arr[i] && (arr[i] > l2 || l1 == l2))
        {
            l2 = arr[i];
        }

        // Find second smallest
        if (arr[i] < s1)
        {
            s2 = s1;
            s1 = arr[i];
        }
        else if (s1 != arr[i] && (arr[i] < s2 || s1 == s2))
        {
            s2 = arr[i];
        }
    }

    if (l1 == l2 || s1 == s2)
    {
        printf("All elements are identical. No second largest or smallest exist.\n");
    }
    else
    {
        printf("Second largest element is: %d \n", l2);
        printf("Second smallest element is: %d \n", s2);
    }

    free(arr);
    return 0;
}