#include<stdio.h>
struct student 
{
	int rno;
	int mark;
};
void display(struct student);
int main()
{
	struct student s1;
	s1.rno=1;
	s1.mark=100;
	display(s1);
	return 0;
}
void display (struct student s1)
{
	printf("roll no :%d \nmark :%d",s1.rno,s1.mark);
}
