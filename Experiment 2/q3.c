#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    printf("Enter m and n: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    int size = 0;

    int *row = NULL;
    int *col = NULL;
    int *val = NULL;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element: ");
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                size++;
                row = realloc(row, size * sizeof(int));
                col = realloc(col, size * sizeof(int));
                val = realloc(val, size * sizeof(int));
                row[size - 1] = i;
                col[size - 1] = j;
                val[size - 1] = matrix[i][j];
            }
        }
    }

    printf("Row Col Val\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d   %d   %d\n", row[i], col[i], val[i]);
    }
}