#include <stdio.h>
#include <stdlib.h>

int *arr;
int size;

void print_array()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse(int l, int r)
{
    while (l < r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void rotate(int n)
{
    n = n % size;
    reverse(0, size - 1);
    reverse(0, n - 1);
    reverse(n, size - 1);
}

int main()
{
    printf("Enter size: ");
    scanf("%d", &size);

    arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int n;
    printf("Enter number of position array is to be rotated: ");
    scanf("%d", &n);

    rotate(n);
    printf("Rotated array -> ");
    print_array();
}