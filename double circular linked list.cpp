#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


void create(int n)
{
    struct node *newnode, *temp;

    for(int i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if(head == NULL)
        {
            head = newnode;
            head->next = head;
            head->prev = head;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = head;
            head->prev = newnode;
            temp = newnode;
        }
    }
}


void insert_begin()
{
    struct node *newnode, *last;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        head->next = head;
        head->prev = head;
        return;
    }

    last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    head = newnode;
}


void insert_end()
{
    struct node *newnode, *last;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        head->next = head;
        head->prev = head;
        return;
    }

    last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;
}


void insert_pos()
{
    int pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        insert_begin();
        return;
    }

    struct node *newnode, *temp = head;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    for(int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}


void delete_begin()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *last = head->prev;
    struct node *temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

    free(temp);
}


void delete_end()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *last = head->prev;
    struct node *newlast = last->prev;

    newlast->next = head;
    head->prev = newlast;

    free(last);
}


void delete_pos()
{
    int pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(pos == 1)
    {
        delete_begin();
        return;
    }

    struct node *temp = head;

    for(int i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}


void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    printf("Forward: ");

    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("(head)\n");
}


int main()
{
    int choice, n;

    while(1)
    {
        printf("\n1.Create\n2.Insert Begin\n3.Insert End\n4.Insert Position\n");
        printf("5.Delete Begin\n6.Delete End\n7.Delete Position\n8.Display\n9.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                insert_begin();
                break;

            case 3:
                insert_end();
                break;

            case 4:
                insert_pos();
                break;

            case 5:
                delete_begin();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                delete_pos();
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
