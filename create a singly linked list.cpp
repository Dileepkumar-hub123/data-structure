#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
}*head;

void create()//CREATE
{
	int choice=1;
	struct node *newnode,*prev;
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter elemet:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		
		if(head==NULL)
		{
			head=newnode;
			prev=newnode;
		}
		else
		{
			prev->next=newnode;
			prev=newnode;
		}
		printf("do you want contiue 1/0 :");
		scanf("%d",&choice);
	}
}
void display()//DISPLAY
{
	struct node *temp;
	temp=head;
	printf("linked list: \n");
	while(head!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	
}
int main()
{
	create();
	display();
	return 0;
}
