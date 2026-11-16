#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *stack;
    int front;
    int size;
};

struct Stack *initialize_stack(int n)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->stack = (int *)malloc(n * sizeof(int));
    s->front = -1;
    s->size = n;
    return s;
}

void print_stack(struct Stack *s)
{
    printf("Stack: ");
    for (int i = 0; i <= s->front; i++)
        printf("%d ", s->stack[i]);
    printf("\n");
}

void push_stack(int val, struct Stack *s)
{
    if (s->front == s->size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->stack[++s->front] = val;
}

int pop_stack(struct Stack *s)
{
    if (s->front == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->stack[s->front--];
}

int top_stack(struct Stack *s)
{
    if (s->front == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    return s->stack[s->front];
}

int main()
{
    struct Stack *s = initialize_stack(5);
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