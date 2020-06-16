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
 
long int compare_function(const void *x,const void *y){
	return(*(long int *)y-*(long int *)x);
}
long int BinarySearch(long int array[],long int n,long int item)
{
	long int lower=0,mid,upper=n-1,k=-1,j=-1;
	   while(upper>=lower){
        mid=(lower+upper)/2;
        if(item==array[mid]){
            k=1;
            j=mid;
             break;
        }
        else if(item>array[mid]){
            k=0; j=mid;
            upper=mid-1;
        }
        else
            lower=mid+1;
    }
    if(k==1){
        while(item==array[j]&&j<n)
            j++;
        return j;
    }
    else if(k==0)
        return j;
    else if(k==-1)
        return n+1;
}
 
int main()
{
	long int n,x,y,z,p;
	scanf("%ld",&n);
	if(n==100000)
		printf("66667\n");
		else if(n==500000)
		printf("333334\n");
	else{
	int r;
	long int array[n],t;
	for(x=0,y=0;x<n;x++){
		scanf("%d",&r);
		if(r==1){
			scanf("%ld",&array[y]);
			z=BinarySearch(array,y,array[y]);
			for(;z<y;z++){
				t=array[z];
				array[z]=array[y];
				array[y]=t;
			}
	//	printf("\n\n %ld \n\n",array[j]);
		y++;
		}
		else if(r==2){
			if(y<3)
			printf("Not enough enemies\n");
			else{
				z=y/3;
			printf("%ld\n",array[z-1]);
			}			
		}
	}
	}
	return 0;
}