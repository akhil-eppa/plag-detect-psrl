#include <stdlib.h>
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);
	while(num--)
	{
		int n,m,i,u,d,l,r, flag=1, N, M;
		scanf("%d %d",&n,&m);
		char arr[1005];
		scanf("%s",arr);
		u=0,l=0,r=0, d=0;
		for(i=0; arr[i]!='\0';i++)
		{	
			
			if(arr[i]=='L')
					{l++;
 
					if(r>0)
					r--;
					if(l==m)
					break;
					}
					
 
			else if(arr[i]=='R')
			{++r;
			
					if(l>0)
					l--;
					if(r==m)
					break;
			
			}
			else if(arr[i]=='U')
			{++u;
				if(d>0)
					d--;
					if(u==n)
					break;
			}
 
			else if(arr[i]=='D')
			{++d;
				if(u>0)
					u--;
					if(d==n)
					break;}
 
			
		}
			
		if(abs(l)<m && abs(r)<m && abs(u)<n && abs(d)<n)
		printf("safe\n");
		else
		printf("unsafe\n");
		}
 
	}              			
	
 
 
 
