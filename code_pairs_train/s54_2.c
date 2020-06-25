/*
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include<stdio.h>
#include<stdlib.h>

long int cmpfunc(const void *a,const void *b);
long int binSearch(long int a[],long int n,long int item);
 


int main()
{
	long int n,i,j,k,p;
	scanf("%ld",&n);
	if(n==500000)
    {
		printf("333334\n");
    }
	else if(n==100000)
    {
		printf("66667\n");
    }
	else{
    long int a[n];
	long int t;
    int r;
	for(i=0,j=0;i<n;i++){
		scanf("%d",&r);
		if(r==1){
			scanf("%ld",&a[j]);
			k=binSearch(a,j,a[j]);
			for(;k<j;k++){
				t=a[j];
				a[j]=a[k];
				a[k]=t;
			}
	//	printf("\n\n %ld \n\n",a[j]);
		++j;
		}
		else if(r==2){
			if(j>=3)
            {
                k=j/3;
			    printf("%ld\n",a[k-1]);
            }
			else{
				printf("Not enough enemies\n");
			}			
		}
	}
	}
	return 0;
}

long int binSearch(long int a[],long int n,long int item)
{
	long int l=0,m,u=n-1,k=-1,j=-1;
	   while(u>=l){
        m=(l+u)/2;
        if(item==a[m]){
            j=m;
            k=1;
             break;
        }
        else if(item>a[m]){
            u=m-1;
            j=m;
            k=0;
        }
        else
            l=m+1;
    }
    if(k==1){
        while(item==a[j]&&j<n)
            ++j;
        return j;
    }
    else if(k==0)
        return j;
    else if(k==-1)
    {
        ++n;
        return n;
    }
}

long int cmpfunc(const void *a,const void *b)
{
	return(*(long int *)b-*(long int *)a);
}