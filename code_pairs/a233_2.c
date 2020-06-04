#include<stdio.h>

char A;
long long ar[1000100];
int compare(long long *a,long long *b){
	if((*a)<(*b))	return -1;
	else if((*a)>(*b))	return 1;
	return 0;
}
int main(){
	long long j,k,l,x,y,z,p;
	z=(1000001);
	x=z*z+z+1;
	p=1;
	int i;
	ar[0]=0;
	i=1;
	while((A=getchar())!='\n'){
		if(A=='A'){
			ar[i]=(ar[i-1]+z*z)%x;
		}else if(A=='B'){
			ar[i]=(ar[i-1]+z)%x;
		}else ar[i]=(ar[i-1]+1)%x;
		i++;
	}

	qsort(ar,i,sizeof(long long),compare);
	
	k=ar[1];
	l=1;
	y=0;
	if(k==0)	y=1;
	
	for(j=2;j<=i;j++){
		
		if(ar[j]==0)	y++;
		if(ar[j]==k){
			l++;
		}else{
			y+=(l*(l-1))/2;	
			l=1;
			k=ar[j];
		}
	}
	y--;
	printf("%lld\n",y);
	return 0;
}
	
