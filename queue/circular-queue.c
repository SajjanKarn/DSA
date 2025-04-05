#include <stdio.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE], front = -1, rear = -1;

// isEmpty
int isEmpty()
{
    return front == -1 && rear == -1;
}

// isFull
int isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

// insert
void insert(int data)
{
    if (isFull())
    {
        printf("Overflow\n");
        return;
    }

    if (rear == -1 && front == -1)
    {
        rear = front = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }

    circularQueue[rear] = data;
    printf("The data %d is inserted\n", data);
}

// delete
int delete()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return -1;
    }
    int deletedItem = circularQueue[front];
    if (front == rear)
    {
        rear = front = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }

    printf("The item %d is deleted\n", deletedItem);
    return deletedItem;
}

// display
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    int i;

    for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
    {
        printf("[%d] ", circularQueue[i]);
    }

    printf("[%d] ", circularQueue[i]);
}

int main()
{

    display();

    insert(1); // rear = front = 0;
    insert(2); // rear = 1
    insert(3); // rear = 2
    insert(4); // rear = 3
    insert(5); // rear = 4
    insert(2); // rear = 4 // should overflow

    delete (); // front = 1
    delete (); // front = 2

    insert(55); // rear = 5
    insert(55); // rear = 6

    display();

    return 0;
}