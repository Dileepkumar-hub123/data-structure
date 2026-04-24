
#include<stdio.h>
void quicksort(int a[],int f,int l)
{
	int i,j,pivot,temp;
	if(f<l)
	{
		pivot=f;
		i=f;
		j=l;
	while(i<j)
	{
		while(a[i]<=a[pivot] && i<j)
		  i++;
		while(a[j]>a[pivot]) 
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;
	quicksort(a,f,j-1);
	quicksort(a,j+1,l);	
	}
	
}

int main()
{
    int a[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("Sorted elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
