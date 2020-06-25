#include <stdio.h>

int main(void) {
	// your code goes here
	int tc,i,no,p[10000],m,j,k,pos;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
	    scanf("%d",&no);
	    for(j=0;j<no;j++)
	        scanf("%d",&p[j]);
	    scanf("%d",&m);
	    int tmp=p[m-1];
	    int tmp1;
	    for(j=0;j<no-1;j++)
	    {
	        pos=p[j];
	        for(k=j+1;k<no;k++)
	        {
	            if(p[j]>p[k])
	              {  pos=p[k];
	              //break;
	              }
	              if(pos!=p[j])
	            {
	            tmp1=p[j];
	            p[j]=pos;
	            p[k]=tmp1;
	            }
	        }
	        
	    }
	    for(j=0;j<no;j++)
	    {
	        if(tmp==p[j])
	            break;
	    }
	    printf("%d\n",j+1);
	}
	return 0;
}

