#include <stdio.h>
int main(void)
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
    int result[size];

    result[0] = 1;
    for (int i = 1; i < size; i++)
    {
        result[i] = result[i - 1] * arr[i - 1];
    }
    int right = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        result[i] *= right;
        right *= arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
