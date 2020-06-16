#include <stdio.h>
int main()
{
	int num,a,b,cmp[1000000],x,N,k,i,n,m,j,w;
	scanf("%d", &num);              			
	for(i=0;i<num;i++)
	{
	    scanf("%d%d",&n,&m);
	   
	    for(j=0;j<m;j++)
	    {N=0;k=0;
	    scanf("%d%d",&a,&b);
	    if((a<b)&&(a<=n))
	    cmp[j]=a;
	    else if((a==b)&&(a<=n))
	    cmp[j]=a;
	    else if((b<a)&&(b<=n))
	    cmp[j]=b;
	    else
	    {printf("NO\n");N=1;
	    break;}
	    
	    
	    x=cmp[j];      //searching an element in an arrray
	    while(k!=j)
	    {
	     N=((x==cmp[k])?1:0);
	     if((N==1)&&(w<=0))
	     {++w;
	         if(x==a){x=b;N=k=0;continue;}else{x=a;N=k=0;continue;}}
	         else if(N==1)
	         {
	   printf("NO\n");
	     break;
	     }
	     ++k;
	    }
	     if(N==1)
	      break;
	     
	      
	   }
	    if(N==0)
	     printf("YES\n");
	}
}