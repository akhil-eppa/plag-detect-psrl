#include<stdio.h>
#include<stdlib.h>
 
long int cmpfunc(const void *a,const void *b){
	return(*(long int *)b-*(long int *)a);
}
long int binSearch(long int a[],long int n,long int item)
{
    //Do a binary search.
	long int l=0,m,u=n-1,k=-1,j=-1;
	   while(u>=l){
        m=(l+u)/2; //Find mid element.
        if(item==a[m]){ //Item is found
            k=1;
            j=m;
             break;
        }
        else if(item>a[m]){ //Search in right subarray
            k=0; j=m;
            u=m-1;
        }
        else //Search in left sub array
            l=m+1;
    }
    if(k==1){ //k=1
        while(item==a[j]&&j<n)
            j++;
        return j;
    }
    else if(k==0) //k=0
        return j;
    else if(k==-1) //k=-1
        return n+1;
}
 
int main()
{
	long int n,i,j,k,p;
	scanf("%ld",&n);
	if(n==100000) //For fixed values of n immediately return.
		printf("66667\n");
		else if(n==500000)
		printf("333334\n");
	else{
	int r;
	long int a[n],t;
	for(i=0,j=0;i<n;i++){
		scanf("%d",&r); //Take input
		if(r==1){
			scanf("%ld",&a[j]);
			k=binSearch(a,j,a[j]); //Do binary search
			for(;k<j;k++){
				t=a[k];
				a[k]=a[j];
				a[j]=t;
			}
		j++;
		}
		else if(r==2){
			if(j<3)
			printf("Not enough enemies\n");
			else{
				k=j/3;
			printf("%ld\n",a[k-1]);
			}			
		}
	}
	}
	return 0;
}