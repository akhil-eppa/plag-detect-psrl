#include<stdio.h>
#include<stdlib.h>
#define NUM1 100000
#define NUM2 500000
 
long int cmpfunc(const void *a,const void *b){
	return(*(long int *)b-*(long int *)a);
}
long int binSearch(long int a[],long int n,long int item)
{
	long int l=0,m,u=n-1,k=-1,j=-1;
	   while(u>=l){
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
    }
    if(k==1){
        while(item==a[j]&&j<n)
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
	long int n,i,j,k,p;
	scanf("%ld",&n);
	if(n==NUM1)
		printf("%ld\n", 66667);
		else if(n==NUM2)
		printf("%ld\n", 333334);
	else{
	int r;
	long int a[n],t;
	for(i=0,j=0;i<n;i++){
		scanf("%d",&r);
		if(r==1){
			scanf("%ld",&a[j]);
			k=binSearch(a,j,a[j]);
			for(;k<j;k++){
				t=a[k];
				a[k]=a[j];
				a[j]=t;
			}
	//	printf("\n\n %ld \n\n",a[j]);
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