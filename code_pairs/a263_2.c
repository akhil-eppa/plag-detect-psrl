#include<stdio.h>

int main()
{
 int T;
 int G[10];
 int I[10][20000];
 int J[10][20000];
 int N[10][20000];
 scanf("%d",&T);
 for(int i=0;i<T;i++)
 	{scanf("%d",&G[i]);
 	 for(int j=0;j<G[i];j++)
 	 	{scanf("%d",&I[i][j]); 
 	 	 scanf("%d",&N[i][j]); 
 	 	 scanf("%d",&J[i][j]);
 	 	}
 	 } 
  for(int i=0;i<T;i++)
  	{
  	 for(int j=0;j<G[i];j++)
  	 	{
  	 	 if((I[i][j])==(J[i][j]))
  	 	 	{printf("%d\n",(N[i][j]/2));}
  	 	 else
  	 	 	{if((N[i][j]%2)==0)
  	 	 	 {printf("%d\n",(N[i][j]/2));}	
  	 	 	 else	 	  	     	 	    		      			 
 			  {printf("%d\n",(N[i][j]/2+1));}
 		 }
 		 }
 	}
 	return 0;
 } 		 	  	