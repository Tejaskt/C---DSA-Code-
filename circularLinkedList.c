// circular single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
}*head=NULL, *last=NULL;

struct node * memo(int data)
{
    struct node * link = (struct node *)malloc(1*sizeof(struct node));
    if(link == NULL)
    {
        printf("memory not assigned");
        exit(1);
    }
    link->data = data;
    link->next = NULL;

    return link;
}

void create(int data)
{
    struct node * link = memo(data);
    if(head == NULL)
    {
        head = link;
        last = link;
        last->next = head;
        return;
    }
    last->next = link;
    last = link;
    last->next = head;
}

void print()
{
    struct node *temp = head;
    //  while(temp!=NULL){

    for(int i=1; i<10; i++)
    {
        printf("    %d \t",temp->data);
        temp = temp->next;
    }
}

void insert_at_begin(int data)
{

    struct node *link = memo(data);

    if(head == NULL)
    {
        last = link;
    }

    link->next = head;
    head = link;
}

void insertAtLast(int data)
{

    struct node *link = memo(data);

    if(head == NULL)
    {
        head = link;
        last = link;
        return;
    }
    last->next = link;
    last = link;
}

void insetAtPos(int pos, int data)
{
    struct node *link = memo(data);
    struct node *temp = head;

    // If the list is empty or position is 1, insert at the beginning
    if (pos == 1 || head == NULL)
    {
        insert_at_begin(data);
        return;
    }

    int count = 1;
    struct node *prev = NULL;

    // Traverse to the position or the end of the list
    while (temp != NULL && count < pos)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If the position is beyond the current list length, insert at the end
    if (temp == NULL)
    {
        insertAtLast(data);
        return;
    }

    // Insert the node at the specific position
    link->next = temp;
    if (prev != NULL)
    {
        prev->next = link;
    }
}


void main()
{
    create(4);
    create(5);
    create(6);
    create(7);
    print();
}