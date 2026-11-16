#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct Stack
{
    struct node *front;
};

struct Stack *initialize_stack()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->front = NULL;
    return s;
}

void print_stack(struct Stack *s)
{
    printf("Stack: ");
    for (struct node *cur = s->front; cur; cur = cur->next)
        printf("%d%s", cur->val, cur->next ? " -> " : "");
    printf("\n");
}

void push_stack(int val, struct Stack *s)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = s->front;
    s->front = temp;
}

int pop_stack(struct Stack *s)
{
    if (s->front == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node *temp = s->front;
    int val = temp->val;
    s->front = temp->next;
    free(temp);
    return val;
}

int top_stack(struct Stack *s)
{
    if (s->front == NULL)
    {
        printf("Stack Empty\n");
        return -1;
    }
    return s->front->val;
}

int main()
{
    struct Stack *s = initialize_stack();
    push_stack(1, s);
    push_stack(2, s);
    push_stack(3, s);
    print_stack(s);
    printf("Popped: %d\n", pop_stack(s));
    printf("Top: %d\n", top_stack(s));
    printf("Popped: %d\n", pop_stack(s));
    print_stack(s);
    return 0;
}