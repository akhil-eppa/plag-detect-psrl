#include <stdio.h>
 
int main()
{
	int t,b,x;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&b);
		long long int max=1,min=1;
		while(b--)
		{
			
			scanf(" %c",&c);
			if(c!='N')
			scanf("%d",&x);
			switch(c)
			{
				case '+': max+=x;
						break;
				case '-': min-=x;
						break;
				case '*': max*=x;
						if(min<1)
						min*=x;
						break;
				case '/':if(min==1) 
						min/=x;
						break;
				case 'N' : if (-min>max)
						max= -min;
						else if(-max<min)
						min=-max;
						break;
			}
		}
		printf("%lld\n",max);
	}
    return 0;
}
