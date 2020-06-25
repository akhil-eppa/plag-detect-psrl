#include <stdio.h>
void sort(long int *ar,int n)
{
    long int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ar[j]>ar[i])
            {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
}
int main() {
	//code
	int i,j,k;
	int n,num;
	long int ar[100];
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
	    scanf("%d",&n);
	    for(j=0;j<n;j++)
	    scanf("%ld",&ar[j]);
	    scanf("%d",&k);
	    k=ar[k-1];
	    sort(ar,n);
	    for(j=0;j<n;j++)
	    {
	        if(ar[j]==k)
	        {
	            k=j+1;
	            break;
	        }
	    }
	    printf("%d\n",k);
	}
	return 0;
}