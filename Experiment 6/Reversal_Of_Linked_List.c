#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
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
}

void reverse_list(struct node **start)
{
    if (*start == NULL || (*start)->next == NULL)
    {
        return;
    }
    struct node *prev = NULL;
    struct node *cur = *start;
    struct node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *start = prev;
}

int main()
{
    struct node *start = NULL;

    insert_end(1, &start);
    insert_end(2, &start);
    insert_end(3, &start);

    print_linked_list(start);

    reverse_list(&start);

    printf("After reversing: ");
    print_linked_list(start);

    return 0;
}