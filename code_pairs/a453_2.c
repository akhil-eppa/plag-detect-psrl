#include<stdio.h>
 
void create(int []);
void down_adjust(int [],int);
 
void main()
{
	int hpe[30],n,i,lastx,temper;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&hpe[i]);
	
	//create a hpe
	hpe[0]=n;
	create(hpe);
	
	//sorting
	while(hpe[0] > 1)
	{
		//swap hpe[1] and hpe[lastx]
		lastx=hpe[0];
		temper=hpe[1];
		hpe[1]=hpe[lastx];
		hpe[lastx]=temper;
		hpe[0]--;
		down_adjust(hpe,1);
	}
 
	//print sorted data
	printf("\nArray after sorting:\n");
	for(i=1;i<=n;i++)
		printf("%d ",hpe[i]);
}
 
void create(int hpe[])
{
	int i,n;
	n=hpe[0]; //no. of elements
	for(i=n/2;i>=1;i--)
		down_adjust(hpe,i);
}
 
void down_adjust(int hpe[],int i)
{
	int j,temper,n,flag=1;
	n=hpe[0];
	
	while(2*i<=n && flag==1)
	{
		j=2*i;	//j points to left child
		if(j+1<=n && hpe[j+1] > hpe[j])
			j=j+1;
		if(hpe[i] > hpe[j])
			flag=0;
		else
		{
			temper=hpe[i];
			hpe[i]=hpe[j];
			hpe[j]=temper;
			i=j;
		}
	}
}