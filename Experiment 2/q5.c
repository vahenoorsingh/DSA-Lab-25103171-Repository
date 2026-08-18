#include <stdio.h>
#include <stdlib.h>

int *arr;
int size;

void print_array(int *a)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertion_sort()
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // print_array(arr);
}

void buble_sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // print_array(arr);
}

int main()
{
    int choice;
    printf("Enter 0 for insert array enter 1 for 100000 reversed elements: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        printf("Enter size: ");
        scanf("%d", &size);
    }
    else
        size = 100000;

    arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        if (choice == 0)
        {
            scanf("%d", &arr[i]);
        }

        // reversed array
        else
        {
            arr[i] = size - i;
        }
    }

    printf("Enter 0 for insertion sort, 1 for bubble sort: ");
    scanf("%d", &choice);

    if (choice == 0)
        insertion_sort();
    else
        buble_sort();
}

// 5.42s user 0.01s system 99% cpu 5.485 total for 100000 reversed elements in insertion sort
// 8.98s user 0.01s system 99% cpu 9.031 total for 100000 reversed elements in bubble sort
