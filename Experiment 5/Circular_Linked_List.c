#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

int get_length(struct node *start);
void print_linked_list(struct node *start);
void print_linked_list_times(struct node *start, int t);
void insert_start(int val, struct node **start, struct node **end);
void insert_end(int val, struct node **start, struct node **end);
void insert_index(int val, int idx, struct node **start, struct node **end);
void delete_start(struct node **start, struct node **end);
void delete_end(struct node **start, struct node **end);
void delete_index(int idx, struct node **start, struct node **end);
void delete_value(int val, struct node **start, struct node **end);
void insert_mid(int val, struct node **start, struct node **end);

int main()
{
    struct node *start = NULL;
    struct node *end = NULL;

    insert_start(1, &start, &end);
    insert_end(2, &start, &end);
    insert_end(4, &start, &end);
    insert_index(0, 0, &start, &end);
    insert_index(3, 3, &start, &end);
    insert_end(5, &start, &end);
    insert_end(6, &start, &end);
    insert_end(7, &start, &end);

    printf("List before deletion: ");
    print_linked_list(start);

    delete_start(&start, &end);
    delete_end(&start, &end);
    delete_index(1, &start, &end);
    delete_value(3, &start, &end);

    printf("List after deletion: ");
    print_linked_list(start);

    insert_mid(3, &start, &end);
    print_linked_list(start);

    return 0;
}

int get_length(struct node *start)
{
    if (start == NULL)
    {
        return 0;
    }
    int count = 0;
    struct node *cur = start;
    do
    {
        count++;
        cur = cur->next;
    } while (cur != start);
    return count;
}

void print_linked_list(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *cur = start;
    while (cur->next != start)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);
}

void print_linked_list_times(struct node *start, int t)
{
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *cur = start;
    for (int i = 0; i < t; i++)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);
}

void insert_start(int val, struct node **start, struct node **end)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return;
    }
    temp->val = val;
    if (*start == NULL)
    {
        *start = temp;
        *end = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = *start;
        (*end)->next = temp;
        *start = temp;
    }
}

void insert_end(int val, struct node **start, struct node **end)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return;
    }
    temp->val = val;
    if (*start == NULL)
    {
        *start = temp;
        *end = temp;
        temp->next = temp;
    }
    else
    {
        temp->next = *start;
        (*end)->next = temp;
        *end = temp;
    }
}

void insert_index(int val, int idx, struct node **start, struct node **end)
{
    int len = get_length(*start);
    if (idx <= 0 || *start == NULL)
    {
        insert_start(val, start, end);
        return;
    }
    if (idx >= len)
    {
        insert_end(val, start, end);
        return;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return;
    }
    temp->val = val;

    struct node *cur = *start;
    for (int i = 0; i < idx - 1; i++)
    {
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;
}

void insert_mid(int val, struct node **start, struct node **end)
{
    int len = get_length(*start);
    insert_index(val, len / 2, start, end);
}

void delete_start(struct node **start, struct node **end)
{
    if (*start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    if (*start == *end)
    {
        free(*start);
        *start = NULL;
        *end = NULL;
        return;
    }
    struct node *temp = *start;
    *start = (*start)->next;
    (*end)->next = *start;
    free(temp);
}

void delete_end(struct node **start, struct node **end)
{
    if (*start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    if (*start == *end)
    {
        free(*start);
        *start = NULL;
        *end = NULL;
        return;
    }
    struct node *cur = *start;
    while (cur->next != *end)
    {
        cur = cur->next;
    }
    struct node *temp = *end;
    cur->next = *start;
    *end = cur;
    free(temp);
}

void delete_index(int idx, struct node **start, struct node **end)
{
    if (*start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    int len = get_length(*start);
    if (idx < 0 || idx >= len)
    {
        return;
    }
    if (idx == 0)
    {
        delete_start(start, end);
        return;
    }
    if (idx == len - 1)
    {
        delete_end(start, end);
        return;
    }

    struct node *cur = *start;
    for (int i = 0; i < idx - 1; i++)
    {
        cur = cur->next;
    }
    struct node *temp = cur->next;
    cur->next = temp->next;
    free(temp);
}

void delete_value(int val, struct node **start, struct node **end)
{
    if (*start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *cur = *start;
    int idx = 0;
    do
    {
        if (cur->val == val)
        {
            delete_index(idx, start, end);
            return;
        }
        cur = cur->next;
        idx++;
    } while (cur != *start);
}