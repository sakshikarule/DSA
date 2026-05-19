#include "stack.h"

void init_stack(stack *ps)
{
    ps->top = -1;
}

void push(stack *ps,int data)
{
    ps->top++;
    ps->arr[ps->top] = data;
}

void pop(stack *ps)
{
    ps->arr[ps->top] = 0;
    ps->top--;
}

int peek(stack *ps)
{
    return ps->arr[ps->top];
}

int stack_full(stack *ps)
{
    if(ps->top == SIZE-1)
        return 1;
    else
        return 0;
}

int stack_empty(stack *ps)
{
    if(ps->top == -1)
        return 1;
    else
        return 0;
}
