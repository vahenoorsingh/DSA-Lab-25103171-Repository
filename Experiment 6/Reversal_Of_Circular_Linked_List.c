#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

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
void reverse_circular_linked_list(struct node **start, struct node **end);
void reverse_list(struct node **start);

int main()
{
    struct node *start = NULL;
    struct node *end = NULL;
    insert_start(1, &start, &end);
    insert_end(2, &start, &end);
    insert_end(3, &start, &end);
    print_linked_list(start);
    reverse_circular_linked_list(&start, &end);
    printf("After reversing: ");
    print_linked_list(start);
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
    int i = 0;
    while (i++ < t)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);
}

void insert_start(int val, struct node **start, struct node **end)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    if (*start == NULL)
    {
        *start = temp;
        (*start)->next = temp;
        *end = temp;
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
    temp->val = val;
    if (*start == NULL)
    {
        *start = temp;
        (*start)->next = temp;
        *end = temp;
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
    if (idx == 0 || *start == NULL)
    {
        insert_start(val, start, end);
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
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
    if (*start == NULL)
    {
        return;
    }
    int i = 0;
    struct node *cur = *start;
    while (cur->next != *start)
    {
        i++;
        cur = cur->next;
    }
    insert_index(val, i / 2 + 1, start, end);
}

void delete_start(struct node **start, struct node **end)
{
    if (*start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = *start;
    (*start) = (*start)->next;
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
    struct node *cur = *start;
    while (cur->next != *end)
        cur = cur->next;
    struct node *temp = *end;
    cur->next = *start;
    free(temp);
}

void delete_index(int idx, struct node **start, struct node **end)
{
    if (*start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    if (idx == 0)
    {
        delete_start(start, end);
    }
    struct node *cur = *start;
    int i = 0;
    while (cur->next != *end && i++ < idx - 1)
        cur = cur->next;
    if (cur->next == *end)
    {
        delete_end(start, end);
        return;
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
    int i = 0;
    while (cur->next != *end && cur->val != val)
    {
        cur = cur->next;
        i++;
    }
    delete_index(i, start, end);
}

void reverse_circular_linked_list(struct node **start, struct node **end)
{
    if (start == NULL || *start == NULL || *start == *end)
    {
        return;
    }

    struct node *prev = *end;
    struct node *cur = *start;
    struct node *next_node = NULL;

    struct node *old_start = *start;

    do
    {
        next_node = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_node;
    } while (cur != old_start);

    *start = *end;
    *end = old_start;
}