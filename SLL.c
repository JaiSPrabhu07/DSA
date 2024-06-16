#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// insert at the end of the list
void insert(int data, struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// insert at the beginning of the list
void begin(int data, struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
    }
}

// insert at position
void inspos(int data, int pos, struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (pos < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        struct node *temp = *head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// insert after position
void after(int data, int pos, struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (pos < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        struct node *temp = *head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// delete the first element of the list
void delfirst(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

// delete the last element of the list
void delend(struct node **head)
{
    struct node *prev = NULL;
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

// delete at position
void delpos(int pos, struct node **head)
{
    struct node *prev = NULL;
    if (pos < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        struct node *temp = *head;
        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

// display the list
void display(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;

    printf("After inserting the element in the end:\n");
    insert(20, &head);
    insert(30, &head);
    display(&head);

    printf("\nAfter inserting the element in the beginning:\n");
    begin(10, &head);
    display(&head);

    printf("\nAfter inserting the element at a position:\n");
    inspos(55, 2, &head);
    display(&head);

    printf("\nAfter inserting the element after a position:\n");
    after(40, 3, &head);
    display(&head);

    printf("\nAfter deleting the first element:\n");
    delfirst(&head);
    display(&head);

    printf("\nAfter deleting the last element:\n");
    delend(&head);
    display(&head);

    printf("\nAfter deleting the element at a position:\n");
    delpos(3, &head);
    display(&head);
}