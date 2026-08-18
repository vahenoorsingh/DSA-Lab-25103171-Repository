#include <stdio.h>
#include <stdlib.h>

int target;
int *arr;
int count = 0;
int *subset = NULL;
int size;
int ans = 0;

void dfs(int i, int sum)
{
    if (sum == target)
    {
        ans++;
        printf("Subset %d -> ", ans);
        for (int i = 0; i < count; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (sum > target || i == size)
    {
        return;
    }

    int inc = sum + arr[i];
    int exc = sum;

    count += 1;
    subset = realloc(subset, (count * sizeof(int)));
    subset[count - 1] = arr[i];
    dfs(i + 1, inc);
    count -= 1;
    subset = realloc(subset, (count * sizeof(int)));

    dfs(i + 1, exc);
}

int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    dfs(0, 0);
    printf("Number of Subset = %d\n", ans);

    return 0;
}