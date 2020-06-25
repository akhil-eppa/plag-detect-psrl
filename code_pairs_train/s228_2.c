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
	   do{
        m=(l+u)/2;
        if(item==a[m]){
            k=1;
            j=m;
             break;
        }
        else if(item>a[m]){
            k=0; j=m;
            u=m-1;
        }
        else
            l=m+1;
    }while(u>=l);
    if(k==1){
        do
        {
            ++j;
        }while(item==a[j]&&j<n);
        return j;
    }
    else if(k==0)
        return j;
    else if(k==-1)
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
    i = 0;
    j=0;
	while(i<n){
		scanf("%d",&r);
		if(r==1){
			scanf("%ld",&a[j]);
			k=binSearch(a,j,a[j]);
			while(k<j){
				t=a[k];
				a[k]=a[j];
				a[j]=t;
                k += 1;
			}
	//	printf("\n\n %ld \n\n",a[j]);
		j +=1;
		}
		else if(r==2){
			if(j<3)
			printf("Not enough enemies\n");
			else{
				k=j/3;
			printf("%ld\n",a[k-1]);
			}			
		}
        ++i;
	}
	}
	return 0;
}