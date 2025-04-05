#include <stdio.h>

#define MAX_SIZE 5

int stack[MAX_SIZE], top = -1;

// isEmpty
int isEmpty()
{
    return top == -1;
}

// isFull
int isFull()
{
    return top == MAX_SIZE - 1;
}

// insert
void insert(int data)
{
    // isFull
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }

    stack[++top] = data;
    printf("The data %d is inserted\n", data);
}

// pop
int pop()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return 0;
    }

    int popValue = stack[top];
    top--;
    return popValue;
}

// display
void display()
{
    if (isEmpty())
    {
        printf("stack empty!\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("[%d] ", stack[i]);
    }
}

int main()
{
    display();

    insert(5);
    display();
    insert(6);
    insert(7);
    insert(9);
    insert(9);

    pop();
    pop();
    pop();
    pop();
    display();
    return 0;
}