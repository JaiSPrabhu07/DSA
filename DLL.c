#include<stdio.h>
#include<stdlib.h>

// sturcture
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

// insert at the end of the list
void insertend(int data,struct node **head){
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev=NULL;
    newnode->next = NULL;
    
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
    }
}

// insert at the beginning of the list
void insertbegin(int data, struct node **head){
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev=NULL;
    newnode->next = NULL;
    
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}

// insert at position
void atpos(int data, int pos, struct node **head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev=NULL;
    newnode->next = NULL;
    
    if(pos<=0){
        printf("Invalid Position\n");
    }
    else{
        struct node *temp=*head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

// insert after position
void afterpos(int data,int pos, struct node **head){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev=NULL;
    newnode->next = NULL;
    
    if(pos<=0){
        printf("Invalid Position\n");
    }
    else{
        struct node *temp=*head;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

// delete the first element of the list
void delfirst(struct node **head){
    struct node *temp=*head;
    struct node *current;
    
    *head=temp->next;
    current=temp->next;
    current->prev=NULL;
    free(temp);
}

// delete the last element of the list
void dellast(struct node **head){
    struct node *temp=*head;
    struct node *current;
    
    while(temp->next!=NULL){
        current=temp;
        temp=temp->next;
    }
    current->next=NULL;
    free(temp);
}

// delete at position
void delpos(int pos, struct node **head){
    struct node *current;
    struct node *del=*head;
    if(pos<0){
        printf("Invalid Position\n");
    }
    else{
        struct node *temp=*head;
        for(int i=1;i<pos;i++){
            current=del;
            del=del->next;
            temp=del->next;
        }
        while(temp!=NULL){
            current->next=del->next;
            temp->prev=current;
            free(del);
        }
        current->next=del->next;
        free(del);
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

int main(){
    struct node *head=NULL;
    
    printf("After inserting the element in the end:\n");
    insertend(20, &head);
    insertend(30, &head);
    display(&head);

    printf("\nAfter inserting the element in the beginning:\n");
    insertbegin(10, &head);
    display(&head);

    printf("\nAfter inserting the element at a position:\n");
    atpos(55, 2, &head);
    display(&head);

    printf("\nInserting the element after a position:\n");
    afterpos(40, 3, &head);
    display(&head);

    printf("\nAfter deleting the first element:\n");
    delfirst(&head);
    display(&head);

    printf("\nAfter deleting the last element:\n");
    dellast(&head);
    display(&head);

    printf("\nAfter deleting the element at a position:\n");
    delpos(3, &head);
    display(&head);
}