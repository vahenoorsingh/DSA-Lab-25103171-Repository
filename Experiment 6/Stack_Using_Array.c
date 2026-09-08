#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *stack;
    int front;
    int size;
};

struct Stack *initialize_stack(int n);
int is_full(struct Stack *stack);
void push_stack(int val, struct Stack **stack);
void print_stack(struct Stack *stack);
int pop_stack(struct Stack **stack);
int top_stack(struct Stack **stack);

int main()
{
    struct Stack *my_stack = initialize_stack(5);
    push_stack(1, &my_stack);
    push_stack(2, &my_stack);
    push_stack(3, &my_stack);
    print_stack(my_stack);
    printf("Popped: %d\n", pop_stack(&my_stack));
    printf("Top: %d\n", top_stack(&my_stack));
    printf("Popped: %d\n", pop_stack(&my_stack));
    print_stack(my_stack);
}

void print_stack(struct Stack *stack)
{
    printf("Stack: ");
    for (int i = 0; i <= stack->front; i++)
    {
        printf("%d ", stack->stack[i]);
    }
    printf("\n");
}

struct Stack *initialize_stack(int n)
{
    struct Stack *new_stack = (struct Stack *)malloc(sizeof(struct Stack));
    new_stack->stack = (int *)malloc(n * sizeof(int));
    new_stack->front = -1;
    new_stack->size = n;
    return new_stack;
}

int is_full(struct Stack *stack)
{
    if (stack->front == stack->size - 1)
        return 1;
    return 0;
}

int is_empty(struct Stack *stack)
{
    if (stack->front == -1)
        return 1;
    return 0;
}

void push_stack(int val, struct Stack **stack)
{
    if (is_full(*stack))
    {
        printf("Stack Overflow");
        return;
    }
    (*stack)->front++;
    (*stack)->stack[(*stack)->front] = val;
}

int pop_stack(struct Stack **stack)
{
    if (is_empty(*stack))
    {
        printf("Stack Underflow");
        return -1;
    }
    int val = (*stack)->stack[(*stack)->front];
    (*stack)->front--;
    return val;
}

int top_stack(struct Stack **stack)
{
    if (is_empty(*stack))
    {
        printf("Stack Empty");
        return -1;
    }
    int val = (*stack)->stack[(*stack)->front];
    return val;
}
