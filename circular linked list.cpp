#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create list
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
            newnode->next = head;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }
    }
}

// Insert at beginning
void insert_begin()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while(temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

// Insert at end
void insert_end()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
}

// Insert at position
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
    temp->next = newnode;
}

// Delete from beginning
void delete_begin()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head, *last = head;

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    while(last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    free(temp);
}

// Delete from end
void delete_end()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head, *prev;

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Delete from position
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

    struct node *temp = head, *prev;

    for(int i = 1; i < pos && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

// Display list
void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    printf("List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("(head)\n");
}

// Main function
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
