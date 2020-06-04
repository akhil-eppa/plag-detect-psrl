#include <stdio.h>
#include<string.h>
int gcd(int,int);
int main(void) {
	 int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,length,r=0,result,i;
        char b[260];
        scanf("%d",&a);
        scanf("%s",b);
        length=strlen(b);
        if(a==0)
        printf("%s\n",b);
        else
        {
        for(i=0;i<length;i++)
        {
            r=r*10+(b[i]-48);
            r=r%a;
        }
        result=gcd(a,r);
        printf("%d\n",result);
        }
    }
	return 0;
}
int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
        return(gcd(b%a,a));
}

