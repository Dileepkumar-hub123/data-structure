#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*front,*rear;

void enqueue(int ele)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=ele;
	n->next=NULL;
	if(front==NULL)
	{
		front=rear=n;
	}else
	{
		rear->next=n;
		rear=n;
	}
}
void dequeue()
{
	struct node *k;
	if(front==NULL)
	printf("queue is empty");
	else
	{
		k=front;
		front=front->next;
		free(k);
	}
}

void display()
{
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
int main()
{
    int choice, ele;

    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;

            case 2:dequeue();break;

            case 3:display();break;

            case 4:exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

