#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *pos = NULL;
    int *neg = NULL;

    int n_pos = 0;
    int n_neg = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            n_pos += 1;
            pos = realloc(pos, (sizeof(int) * n_pos));
            pos[n_pos - 1] = arr[i];
        }
        else
        {
            n_neg += 1;
            neg = realloc(neg, (sizeof(int) * n_neg));
            neg[n_neg - 1] = arr[i];
        }
    }

    int *ans = malloc(size * sizeof(int));

    if (abs(n_pos - n_neg) > 1)
    {
        printf("Not Possible");
        return 0;
    }

    if (n_pos > n_neg)
    {
        ans[0] = pos[0];
        int j = 1;
        for (int i = 0; i < n_pos; i++)
        {
            ans[j++] = neg[i];
            if (i >= n_pos)
                break;
            ans[j++] = pos[i + 1];
        }
    }
    else if (n_pos == n_neg)
    {
        int j = 0;
        for (int i = 0; i < n_pos; i++)
        {
            ans[j++] = neg[i];
            ans[j++] = pos[i];
        }
    }
    else
    {
        ans[0] = neg[0];
        int j = 1;
        for (int i = 0; i < n_neg; i++)
        {
            ans[j++] = pos[i];
            if (i >= n_neg)
                break;
            ans[j++] = neg[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", ans[i]);
    }

    return 0;
}