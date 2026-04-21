#include<stdio.h>
int b[50];
void merge(int a[],int lb,int mid,int up)
{
	int i=lb,j=mid+1,k=lb;
	while(i<=mid&&j<=up)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=up)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(k=lb;k<=up;k++)
	{
		a[k]=b[k];
	}
}
void mergesort(int a[],int lb,int up)
{
	if(lb<up)
	{
	int mid=(lb+up)/2;
	mergesort(a,lb,mid);
	mergesort(a,mid+1,up);
	merge(a,lb,mid,up);
	}
}
int main()
{
	int a[50],i,n;
	printf("enter the size of the array:");
	scanf("%d",&n);
	printf("enter the array of elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	mergesort(a,0,n-1);
	printf("sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
	
}


