#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

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

void insert_end(int val, struct node **start)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (*start == NULL)
    {
        *start = temp;
        return;
    }

    struct node *cur = *start;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
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

int main()
{
    struct node *start = NULL;

    insert_end(1, &start);
    insert_end(2, &start);
    insert_end(3, &start);

    print_linked_list(start);

    reverse_doubly_linked_list(&start);

    printf("After reversing: ");
    print_linked_list(start);

    return 0;
}