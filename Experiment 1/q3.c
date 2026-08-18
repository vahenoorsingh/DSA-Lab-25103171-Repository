#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct employee
{
    int id;
    char name[50];
    int salary;
};

int main()
{
    struct employee *data = NULL;
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);

    data = malloc(size * sizeof(struct employee));

    for (int i = 0; i < size; i++)
    {
        printf("Enter id: ");
        scanf("%d", &data[i].id);
        printf("Enter name: ");
        while (getchar() != '\n')
            ;
        fgets(data[i].name, (50 * sizeof(char)), stdin);
        data[i].name[strcspn(data[i].name, "\n")] = 0;
        printf("Enter salary: ");
        scanf("%d", &data[i].salary);
    }

    FILE *f = fopen("data.txt", "rb+");

    if (f == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        fwrite(&data[i], sizeof(struct employee), 1, f);
    }

    rewind(f);

    struct employee emp;
    while (fread(&emp, sizeof(struct employee), 1, f))
    {
        if (emp.salary > 50000)
        {
            emp.salary = emp.salary + (5 * emp.salary) / 100;
            fseek(f, -((long)sizeof(struct employee)), SEEK_CUR);
            fwrite(&emp, sizeof(struct employee), 1, f);
            fflush(f);
        }
        else if (emp.salary <= 50000 && emp.salary > 20000)
        {
            emp.salary = emp.salary + (10 * emp.salary) / 100;
            fseek(f, -((long)sizeof(struct employee)), SEEK_CUR);
            fwrite(&emp, sizeof(struct employee), 1, f);
            fflush(f);
        }
        else
        {
            emp.salary = emp.salary + (15 * emp.salary) / 100;
            fseek(f, -((long)sizeof(struct employee)), SEEK_CUR);
            fwrite(&emp, sizeof(struct employee), 1, f);
            fflush(f);
        }
    }

    rewind(f);

    printf("---Updated Record---\n");

    while (fread(&emp, sizeof(struct employee), 1, f))
    {
        printf("id : %d\n", emp.id);
        printf("name : %s\n", emp.name);
        printf("salary : %d\n", emp.salary);
    }

    fclose(f);
}