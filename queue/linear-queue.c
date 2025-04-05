#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE], front = 0, rear = -1;

// isEmpty
int isEmpty()
{
    return front > rear;
}

// isFull
int isFull()
{
    return rear == MAX_SIZE - 1;
}

// insert
void insert(int data)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }

    queue[++rear] = data;
    printf("The %d is inserted\n", data);
}

// delete
int delete()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return 0;
    }

    int deletedItem = queue[front];
    front++;
    printf("%d is deleted\n", deletedItem);
    return deletedItem;
}

// display
void display()
{
    if (isEmpty())
    {
        printf("Empty queue\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("[%d] ", queue[i]);
    }
}

int main()
{
    display();
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    delete ();
    delete ();

    display();
    return 0;
}