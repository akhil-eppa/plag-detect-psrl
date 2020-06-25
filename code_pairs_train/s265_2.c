#include <stdio.h>
//static unsigned long long c;
/*void sos(int sum,int k,unsigned long long int r,unsigned int X[],unsigned int A[],unsigned int K)
{
	X[k]=1;
	if(sum+A[k]<=K)
      c=c+1;
	  else if(sum+A[k]+A[k+1]<=K)
	  {
		  c=c+1;
		  sos(sum+A[k],k+1,r-A[k],X,A,K);
	  }
	  if(sum+r-A[k]>=K && sum+A[k+1]<=K)
       {
		   X[k]=0;
		   sos(sum,k+1,r-A[k],X,A,K);
	   }
	
}*/
void main(){
	unsigned long int T;
	unsigned long long int i,j,k,l,m,p,q;
	
  unsigned long d=pow(10,9)+7;
 unsigned long long c,sum;
	scanf("%ul", &T);              			
	for(i=0;i<T;i++)
	{
		c=0;
        unsigned long int N,M,in=0;
			unsigned long long int size,K;
		scanf("%lu %lu %llu",&N,&M,&K);
		 size=N*M;
		unsigned long int A[N],B[size],X[size],t;
		for(j=0;j<N;j++)
		scanf("%lu",&A[j]);
		/*for(p=0;p<N;p++)
		for(q=p+1;q<N;q++)
		if(A[p]>A[q])
		{
		t=A[p];
		A[p]=A[q];
		A[q]=t;
		}*/
		//for(p=0;p<N;p++)
		//sum=sum+M*A[p];
		
		for(k=0;k<M;k++)
		for(l=0;l<N;l++)
		B[in++]=A[l];
		//ss(0,0,sum,X,B,K);
        for(j=0;j<N;j++)
		if(A[j]<=K)
		c=c+M;
		for(p=0;p<size;p++)
		{
			sum=B[p];
		for(q=p+1;q<size;q++)
		if(sum+B[q]<=K)
		{
		c++;
		sum+=B[q];
		}
		else
		break;
		}
		c=c % d;
		printf("%llu\n",c);
        
 
	}
}
 