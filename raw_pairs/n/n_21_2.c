#include<stdio.h>
#include<stdlib.h>
#define cv const void*
int n,k,t,i,j,s;
int cmp(cv, cv);
int main(){
	for(scanf("%d",&t);t;--t){
		scanf("%d%d",&n,&k);
		int a[n],b[n];s=0;
		for(i=0;i<n;s+=a[i],++i)scanf("%d",&a[i]);
		for(i=0;i<n;++i)scanf("%d",&b[i]);
		qsort(a,n,sizeof(int),cmp);
		qsort(b,n,sizeof(int),cmp);
		i=0,j=n;
		while(k--&&i<n&&j--&&b[j]>a[i])s+=b[j]-a[i],++i;
		printf("%d\n",s);
	}
}
int cmp(cv a,cv b){
	return (*(int*)a-*(int*)b);
}
