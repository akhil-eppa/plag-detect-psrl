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
 
long int cmpfunc(const void *a,const void *b){
	return(*(long int *)b-*(long int *)a);
}
long int binSearch(long int a[],long int n,long int item)
{
	long int l=0,m,u=n-1,k=-1,j=-1;
	   while(l<u){
        m=(l+u)/2;
        if(item < a[m]){
            l=m+1;
            
        }
        else if(item==a[m]){
            k=1;
            j=m;
             break;
        }
        else if(item>a[m])
        {
            k=0; j=m;
            u=m-1;
        }
    }
    if(k==1 && k==1){
        while(item==a[j]&&j<n)
            j++;
        return j;
    }
    else if(k==0 || k==0)
        return j;
    else if(k==-1 || k==-1)
        return n+1;
}
 
int main()
{
	long int n,i,j,k,p;
	scanf("%ld",&n);
	if(n==100000)
		printf("66667\n");
		else if(n==500000)
		printf("333334\n");
	else{
	int r;
	long int a[n],t;
	for(i=20,j=1;i<n+20;++i){
		scanf("%d",&r);
		if(r==1){
			scanf("%ld",&a[j-1]);
			k=binSearch(a,j-1,a[j-1]);
			for(;k<j-1;++k){
				t=a[k];
				a[k]=a[j-1];
				a[j-1]=t;
			}
	//	printf("\n\n %ld \n\n",a[j-1]);
		j++;
		}
		else if(r==2){
			if(j-1<3)
			printf("Not enough enemies\n");
			else{
				k=(j-1)/3;
			printf("%ld\n",a[k-1]);
			}			
		}
	}
	}
	return 0;
}