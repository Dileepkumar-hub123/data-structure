#include<stdio.h>
#include<string.h>
struct dob
{
	int date;
	char month[8];
	int year;
};
struct student
{
   int rollno;
   char name[20];
   struct dob d;
   
};
int main()
{
	struct student s1={1,"dileep"};
	s1.d.date=06;
    strcpy(s1.d.month,"jan");
    s1.d.year=2007;
    
    printf("%d %s %d-%s-%d\n",s1.rollno,s1.name,s1.d.date,s1.d.month,s1.d.year);
    
    printf("%d\n",sizeof(s1));
   
    return 0;

}
