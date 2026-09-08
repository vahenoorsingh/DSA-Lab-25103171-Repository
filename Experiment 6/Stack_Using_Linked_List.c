#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct Stack
{
    struct node *stack;
    struct node *front;
};

struct Stack *initialize_stack();
int is_full(struct Stack *stack);
void push_stack(int val, struct Stack **stack);
void print_stack(struct Stack *stack);
int pop_stack(struct Stack **stack);
int top_stack(struct Stack **stack);

int main()
{
    struct Stack *my_stack = initialize_stack();
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
    struct node *cur = stack->front;
    while (cur->next != NULL)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("%d", cur->val);
    printf("\n");
}

struct Stack *initialize_stack()
{
    struct Stack *new_stack = (struct Stack *)malloc(sizeof(struct Stack));
    new_stack->front = NULL;
    new_stack->stack = NULL;
    return new_stack;
}

int is_empty(struct Stack *stack)
{
    if (stack->stack == NULL)
        return 1;
    return 0;
}

void push_stack(int val, struct Stack **stack)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    if ((*stack)->stack == NULL)
    {
        (*stack)->stack = temp;
    }
    temp->next = (*stack)->front;
    (*stack)->front = temp;
}

int pop_stack(struct Stack **stack)
{
    if (is_empty(*stack))
    {
        printf("Stack Underflow");
        return -1;
    }
    int val = (*stack)->front->val;
    struct node *temp = (*stack)->front;
    (*stack)->front = temp->next;
    free(temp);
    return val;
}

int top_stack(struct Stack **stack)
{
    if (is_empty(*stack))
    {
        printf("Stack Empty");
        return -1;
    }
    int val = (*stack)->front->val;
    return val;
}
