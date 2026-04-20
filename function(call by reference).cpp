#include<stdio.h>
struct student 
{
	int rno;
	int mark;
};
void update(struct student*);
int main()
{
	struct student s1;
	s1.rno=1;
	s1.mark=100;
	update(&s1);
	return 0;
}
void update (struct student*s1)
{	printf("roll no :%d \nmark :%d\n",s1->rno,s1->mark);
	s1->mark=s1->mark + 5;
	printf("roll no :%d \nupdated mark :%d",s1->rno,s1->mark);
}
