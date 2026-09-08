#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

void print_linked_list(struct node *start);
void insert_start(int val, struct node **start);
void insert_end(int val, struct node **start);
void reverse_list(struct node **start);
void insert_index(int val, int idx, struct node **start);

int main()
{
    struct node *start = NULL;
    insert_start(1, &start);
    insert_end(2, &start);
    insert_end(3, &start);
    insert_index(2, 2, &start);
    print_linked_list(start);
    reverse_list(&start);
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
    while (cur->next != NULL)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);
}

void insert_start(int val, struct node **start)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    if (*start == NULL)
    {
        *start = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = *start;
        *start = temp;
    }
}

void insert_end(int val, struct node **start)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    struct node *cur = *start;
    if (cur == NULL)
    {
        insert_start(val, start);
        return;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

void insert_index(int val, int idx, struct node **start)
{
    if (idx == 0 || *start == NULL)
    {
        insert_start(val, start);
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

void reverse_list(struct node **start)
{
    if (*start == NULL || (*start)->next == NULL)
    {
        return;
    }
    struct node *prev = *start;
    struct node *cur = (*start)->next;
    struct node *next = (*start)->next->next;

    prev->next = NULL;
    while (next != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    *start = cur;
}