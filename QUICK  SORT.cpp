#include<stdio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void quick(int a[],int low,int high)

{
	int i,j,pivot;
	if(low<high)
	{
		pivot=a[low];
		i=low+1;
		j=high;
		while(i<=j)
		{
			while( i<=j && a[i]<=pivot)
			{
				i++;
			}
			while(a[j]>pivot)
			{
				j--;
			}
			if(i<j)
			{
				swap(&a[i],&a[j]);
			}
		}
		swap(&a[low], &a[j]);
		
		quick(a,low,j-1);
		quick(a,j+1,high);
	}
}
int main()
{
	int n,i ;
	printf("enter n value :");
	scanf("%d",&n);
	
	int a[n];
	
	printf("enter array :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick(a,0,n-1);
	
	printf("sorted array :");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
	printf("\n sorted array in reverse:");
	for(i=n-1;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
