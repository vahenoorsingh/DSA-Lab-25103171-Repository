#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

void print_linked_list(struct node *start);
void insert_start(int val, struct node **start);
void insert_end(int val, struct node **start);
void reverse_list(struct node **start);
void insert_index(int val, int idx, struct node **start);
void reverse_doubly_linked_list(struct node **start);

int main()
{
    struct node *start = NULL;
    insert_start(1, &start);
    insert_end(2, &start);
    insert_end(3, &start);
    print_linked_list(start);
    reverse_doubly_linked_list(&start);
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
    temp->prev = NULL;
    if (*start == NULL)
    {
        *start = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = *start;
        (*start)->prev = temp;
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
    temp->prev = cur;
}

void insert_index(int val, int idx, struct node **start)
{
    if (idx == 0 || *start == NULL)
    {
        insert_start(val, start);
        return;
    }
    struct node *cur = *start;
    for (int i = 0; i < idx - 1; i++)
    {
        cur = cur->next;
    }
    if (cur->next == NULL)
    {
        insert_end(val, start);
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;

    temp->next = cur->next;
    cur->next = temp;
    temp->next->prev = temp;
    temp->prev = cur;
}

void reverse_doubly_linked_list(struct node **start)
{
    if (*start == NULL || (*start)->next == NULL)
    {
        return;
    }
    struct node *prev = NULL;
    struct node *cur = *start;

    while (cur != NULL)
    {
        prev = cur->prev;
        cur->prev = cur->next;
        cur->next = prev;
        cur = cur->prev;
    }

    *start = prev->prev;
}