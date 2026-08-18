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
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    printf("Duplicate element: %d\n", slow);
    return 0;
}