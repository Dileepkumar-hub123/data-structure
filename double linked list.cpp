#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create list
void create(int n) {
    struct node *newnode, *temp;
    
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

// Insert at beginning
void insert_begin() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;
}

// Insert at end
void insert_end() {
    struct node *newnode, *temp = head;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at position
void insert_pos() {
    int pos, i;
    
    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1) {
        insert_begin();
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    struct node *temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

// Delete from beginning
void delete_begin() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete from end
void delete_end() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Delete from position
void delete_pos() {
    int pos, i;
    
    printf("Enter position: ");
    scanf("%d", &pos);

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    if(pos == 1) {
        delete_begin();
        return;
    }

    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}


void display() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


int main() {
    int choice, n;

    while(1) {
        printf("\n1.Create\n2.Insert Begin\n3.Insert End\n4.Insert Position\n");
        printf("5.Delete Begin\n6.Delete End\n7.Delete Position\n8.Display\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
