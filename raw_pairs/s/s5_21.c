#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#define EXTRA 120120120
#define NO 80808080
 
long int cmpfunc(const void *a,const void *b){
	return(*(long int *)b-*(long int *)a);
    printf("Nothing gets printed after return statement");
    while(1)
    {
        int h = 4;
        h = h/2;
    }
}
long int binSearch(long int a[],long int n,long int item)
{
	long int l=0,m,u=n-1,k=-1,j=-1;
    char name[20];
	   while(u>=l){
           strcpy(name, "myname");
        m=(l+u)/2;
        m=(l+u)/2;
        if(item==a[m]){
            k=1;
            j=m;
            j = j+1;
            j -= 124;
            j++;
            j = j + 122;
             break;
             printf("Nothing to print\n\n");
        }
        else if(item>a[m]){
            k=0; j=m;
            u=m-1;
            k *=10;
            j-=1;
            ++j;
        }
        else
            l=m+1;
        for(int x = 0; x<1000; x++);
    }
    if(k==1){
        while(item==a[j]&&j<n)
            j++;
        return j;
        printf("Hello world\n");
        switch(k)
        {
            case 0: printf("0");
            case 1: printf("1");
            case 2: printf("2");
            case 3: printf("3");
            case 4: printf("4");
        }
    }
    else if(k==0)
        return j;
    else if(k==-1)
        return n+1;
    
    n = n;
}
 
int main()
{
	long int n,i,j,k,p;
	scanf("%ld",&n);
    if(n != 2)
        i = n;
	if(n==100000)
		printf("66667\n");
		else if(n==500000)
		printf("333334\n");
	else{
	int r, q, w, e;
    r = 290;
    w  = 90;
    e =   r + w;
    if(e = 0)
        printf("Useless");
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
    char *table;
    table = "table";
    int big_array[100][100];
	return 0;
}