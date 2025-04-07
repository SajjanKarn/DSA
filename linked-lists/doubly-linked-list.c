// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeg(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    printf("%d inserted at beg\n", data);
}

void insertAtEnd(int data)
{

    if (head == NULL)
    {
        insertAtBeg(data);
        return;
    }

    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;

    printf("%d inserted at end\n", data);
}

void insertAtKPos(int kPos, int data)
{
    if (kPos <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (kPos == 1)
    {
        insertAtBeg(data);
        return;
    }

    int position = 1;
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    while (position < kPos - 1)
    {
        temp = temp->next;
        position++;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("%d inserted at pos %d\n", data, kPos);
}

void deleteAtBeg()
{
    if (head == NULL)
    {
        printf("List is already empty!");
        return;
    }

    struct Node *temp = head;

    printf("%d deleted from beg\n", temp->data);
    temp->next->prev = NULL;
    head = temp->next;

    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is already emtpy!");
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("%d deleted from last\n", temp->next->data);
    free(temp->next->next);
    temp->next = NULL;
}

void deleteAtKPos(int kPos)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (kPos <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    // Deleting the first node
    if (kPos == 1)
    {
        deleteAtBeg();
        return;
    }

    struct Node *temp = head;
    int position = 1;

    // Traverse to the node just before the one to delete
    while (position < kPos - 1)
    {
        temp = temp->next;
        position++;
    }

    // Check if the position is valid
    if (temp->next == NULL)
    {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node *toDelete = temp->next;

    temp->next = toDelete->next;

    // If toDelete is not the last node
    if (toDelete->next != NULL)
    {
        toDelete->next->prev = temp;
    }

    printf("%d deleted from pos %d\n", toDelete->data, kPos);
    free(toDelete);
}

void traverse()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("[%d] -> ", temp->data);
        if (temp->next == NULL)
        {
            printf("NULL");
        }
        temp = temp->next;
    }
}

int main()
{

    insertAtBeg(2);
    insertAtBeg(3);

    insertAtEnd(5);
    insertAtEnd(7);

    insertAtKPos(2, 10);

    deleteAtBeg();
    deleteAtEnd();

    deleteAtKPos(2);

    traverse();

    return 0;
}