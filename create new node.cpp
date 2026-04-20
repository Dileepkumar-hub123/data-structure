#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node)); 

    newnode->data = 10;
    newnode->next = NULL;

    printf("%d", newnode->data);

    return 0;
}
