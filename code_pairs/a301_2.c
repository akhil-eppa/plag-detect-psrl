#include <stdio.h>
int comparator(const void *p, const void *q) 
{ 
    int *x,*y;
    x=(int *)p;
    y=(int *)q;
    return(*x - *y);
} 
int main(void) {
	int t;
	scanf("%d",&t);
	if(t>0 && t<101)
	{
	    while(t--)
	    {
	      int n,k;
	      scanf("%d%d",&n,&k);
	      if(n>0 &&  n<101 && k>0 && k<100 && k<n)
	      {
	          int* w=(int*)malloc(n*sizeof(int));int total=0;
	          for(int i=0;i<n;i++){
	            scanf("%d",&w[i]);total+=w[i];}
	       qsort(w,n,sizeof(int),comparator);
	       int min;
	       if((n-k)<=k)
	            min=(n-k);
	        else
	            min=k;
	       int sum=0;
	       for(int i=0;i<min;i++)
	            sum+=w[i];
	            
	       printf("%d\n",((total-sum)-sum));
	       
	       

	      }else
	      exit(0);
	    }
	    
	}
}

