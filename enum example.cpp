#include<stdio.h>
enum day {MON=2,TUE,WED,THURS,FRI,SAT};
int main()
{
	enum day today;
	
	today =WED;
	printf("Today is a day number :%d\n",today);
	return 0;
}
