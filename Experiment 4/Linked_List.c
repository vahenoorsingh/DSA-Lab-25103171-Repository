#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *insert_start(int val, struct node *start);
struct node *insert_end(int val, struct node *start);
struct node *insert_index(int val, int index, struct node *start);
struct node *insert_middle(int val, struct node *start);
struct node *delete_val(int val, struct node *start);
struct node *delete_index(int index, struct node *start);
void print_linked_list(struct node *start);

int main()
{
    struct node *start = NULL;

    start = insert_end(20, start);
    start = insert_start(10, start);
    start = insert_end(40, start);
    start = insert_index(50, 10, start);
    start = insert_middle(30, start);

    print_linked_list(start);

    start = delete_index(3, start);
    start = delete_val(50, start);
    start = delete_index(10, start);

    print_linked_list(start);

    return 0;
}

struct node *insert_start(int val, struct node *start)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return start;

    temp->val = val;
    temp->next = start;
    return temp;
}

struct node *insert_end(int val, struct node *start)
{
    if (start == NULL)
    {
        return insert_start(val, start);
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;

    struct node *cur = start;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    return start;
}

struct node *insert_index(int val, int index, struct node *start)
{
    if (index < 0)
    {
        printf("Invalid Index %d\n", index);
        return start;
    }
    if (index == 0 || start == NULL)
    {
        return insert_start(val, start);
    }

    struct node *cur = start;
    for (int i = 0; i < index - 1; i++)
    {
        if (cur->next == NULL)
        {
            printf("Index %d is out of bound, inserted at end of Linked List\n", index);
            return insert_end(val, start);
        }
        cur = cur->next;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = cur->next;
    cur->next = temp;

    return start;
}

struct node *insert_middle(int val, struct node *start)
{
    if (start == NULL)
    {
        return insert_start(val, start);
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;

    struct node *slow = start;
    struct node *fast = start;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = slow->next;
    slow->next = temp;
    return start;
}

struct node *delete_index(int index, struct node *start)
{
    if (start == NULL)
    {
        printf("List is already empty\n");
        return NULL;
    }
    if (index < 0)
    {
        printf("Invalid Index %d\n", index);
        return start;
    }

    if (index == 0)
    {
        struct node *temp = start->next;
        free(start);
        return temp;
    }

    struct node *cur = start;
    for (int i = 0; i < index - 1; i++)
    {
        if (cur->next == NULL)
        {
            printf("Index %d is out of bound, deletion failed\n", index);
            return start;
        }
        cur = cur->next;
    }

    if (cur->next == NULL)
    {
        printf("Index %d is out of bound, deletion failed\n", index);
        return start;
    }

    struct node *temp = cur->next;
    cur->next = cur->next->next;
    free(temp);

    return start;
}

struct node *delete_val(int val, struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty, cannot delete %d\n", val);
        return NULL;
    }

    if (start->val == val)
    {
        return delete_index(0, start);
    }

    struct node *cur = start;
    while (cur->next != NULL && cur->next->val != val)
    {
        cur = cur->next;
    }

    if (cur->next == NULL)
    {
        printf("Value %d is not available in linked list\n", val);
        return start;
    }

    struct node *temp = cur->next;
    cur->next = temp->next;
    free(temp);

    return start;
}

void print_linked_list(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
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