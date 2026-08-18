#include <stdio.h>
#include <stdlib.h>

int *arr;
int size;

void print_array()
{
    printf("Array -> ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int idx, int value)
{
    if (idx < 0 || idx > size)
    {
        printf("Invalid Index\n");
        return;
    }
    arr = realloc(arr, (++size) * sizeof(int));
    for (int i = size - 1; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx] = value;
    print_array();
}

void delete(int idx)
{
    if (idx < 0 || idx >= size)
    {
        printf("Invalid Index\n");
        return;
    }
    for (int i = idx; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr = realloc(arr, (--size) * sizeof(int));
    print_array();
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

    print_array();

    int choice = 2;

    while (1)
    {
        printf("Enter 0 for insert, 1 for delete, 2 for exit: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            int idx, value;
            printf("Enter index: ");
            scanf("%d", &idx);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(idx, value);
        }
        else if (choice == 1)
        {
            int idx;
            printf("Enter index: ");
            scanf("%d", &idx);
            delete(idx);
        }
        else
        {
            break;
        }
    }
}
