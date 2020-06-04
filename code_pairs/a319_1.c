#include <stdio.h>
#include<string.h>
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int a,i;
        char s[250];
        scanf("%lld %s",&a,s);
        if(a==0)
        printf("%s\n",s);
        else
        {
          int num=0;
          int l;
          l=strlen(s);
          for(i=0;i<l;i++)
          {
              num=((num*10)+(s[i]-'0'))%a;
          }
          printf("%d\n",gcd(a,num));
        }
    }
}
