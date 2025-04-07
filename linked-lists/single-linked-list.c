// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nextNode;
};

struct Node *head = NULL;

void insertAtBeg(int data)
{
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (temp == NULL)
    {
        head = newNode;
        newNode->nextNode = NULL;
    }
    else
    {
        newNode->nextNode = head;
        head = newNode;
    }

    printf("%d inserted at beginning\n", data);
}

void insertAtEnd(int data)
{
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;

    if (temp == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->nextNode != NULL)
        {
            temp = temp->nextNode;
        };
        temp->nextNode = newNode;
    }

    printf("%d inserted at end\n", data);
}

void insertAtKPos(int kPos, int data)
{
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    int position = 1;

    if (kPos <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (kPos == 1)
    {
        newNode->nextNode = head;
        head = newNode;
        return;
    }

    if (temp == NULL)
    {
        head = newNode;
        newNode->nextNode = NULL;
    }
    else
    {
        while (position < kPos - 1)
        {
            temp = temp->nextNode;
            position++;
        }
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
    }

    printf("%d inserted at pos %d\n", data, position);
}

void traverse()
{

    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("[%d] ->", temp->data);
        if (temp->nextNode == NULL)
        {
            printf(" NULL");
        }
        temp = temp->nextNode;
    }
}

void deleteAtBeg()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }

    printf("%d deleted\n", temp->data);
    head = temp->nextNode;
    free(temp);
}

void deleteAtEnd()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is emtpy!");
        return;
    }

    // if only one node
    if (head->nextNode == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while (temp->nextNode->nextNode != NULL)
    {
        temp = temp->nextNode;
    };

    printf("%d deleted\n", temp->nextNode->data);
    free(temp->nextNode);
    temp->nextNode = NULL;
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
        printf("Invalid position\n");
        return;
    }

    // If deleting the first node
    if (kPos == 1)
    {
        deleteAtBeg();
        return;
    }

    struct Node *temp = head;
    int position = 1;

    // Traverse to the node before the one to delete
    while (temp != NULL && position < kPos - 1)
    {
        temp = temp->nextNode;
        position++;
    }
    printf("\n%d", temp->data);

    // Check if position is valid
    if (temp == NULL || temp->nextNode == NULL)
    {
        printf("Position %d is out of bounds\n", kPos);
        return;
    }

    struct Node *nodeToDelete = temp->nextNode;
    temp->nextNode = nodeToDelete->nextNode;

    printf("\n%d deleted from position %d\n", nodeToDelete->data, kPos);
    free(nodeToDelete);
}

int main()
{

    insertAtBeg(4);
    insertAtBeg(3);
    insertAtBeg(5);

    insertAtKPos(1, 43);

    insertAtEnd(40);
    insertAtEnd(55);

    traverse();

    deleteAtKPos(2);

    traverse();

    return 0;
}