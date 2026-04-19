#include<stdio.h>
struct student
{
	int si;
	char name[20];
	float mark;
};
int main()
{
	int i,n;
	
	printf("enter n value :");
	scanf(" %d",&n);
	
	struct student s[10];
	for(i=0;i<n;i++)
	{
		printf("enter si no:");
		scanf("%d",&s[i].si);
		
		printf("enter name:");
		scanf("%s",&s[i].name);
		
		printf("enter mark:");
		scanf("%f",&s[i].mark);
		
	}
	for(i=0;i<n;i++)
	{
		printf("%-3d %-20s %-5f \n",s[i].si,s[i].name,s[i].mark);
	}
}
