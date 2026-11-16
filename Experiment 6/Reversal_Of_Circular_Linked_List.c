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
    while (cur->next != start)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d\n", cur->val);
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

void reverse_circular_linked_list(struct node **start, struct node **end)
{
    if (*start == NULL || *start == *end)
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

int main()
{
    struct node *start = NULL;
    struct node *end = NULL;

    insert_end(1, &start, &end);
    insert_end(2, &start, &end);
    insert_end(3, &start, &end);

    print_linked_list(start);

    reverse_circular_linked_list(&start, &end);

    printf("After reversing: ");
    print_linked_list(start);

    return 0;
}