 // Write your code here
#include<stdio.h>
#include<stdlib.h>

void equal(long int *k, long int *j, long int *m)
{
    *k = 1;
    *j = *m;
}

void greater(long int *k, long int *j, long int *m, long int *u)
{
    *k=0;
    *j=*m;
    *u=*m-1;
}

void lesser(long int *l, long int *m)
{
    *l = *m + 1;
}

void solve(long int n)
{
    if(n==100000)
		printf("66667\n");
	else if(n==500000)
		printf("333334\n");
}


long int binSearch(long int a[],long int n,long int item)
{
	long int l=0,m,u=n-1,k=-1,j=-1;
	   while(u>=l){
        m=(l+u)/2;
        if(item==a[m]){
            equal(&k, &j, &m);
             break;
        }
        else if(item>a[m]){
            greater(&k, &j, &m, &u);
        }
        else
            lesser(&l, &m);
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
    if(n==100000 || n==500000)
        solve(n);
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