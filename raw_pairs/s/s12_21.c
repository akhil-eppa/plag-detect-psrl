#include<stdio.h>
/*
char* tostring(int num)
{
    int i, rem, len = 0, n;
    char str[14];
    n = num;
    while (n != 0)
    {     len++;
          n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
        
    }
    str[len] = '\0';
    return str;
 
}
*/
/*
long long num(char arr[])
{
    int i;
    long long num=0;
    for(i=0;arr[i]!='\0';i++)
    num=num*10+arr[i]-48;
    return num;
}
*/
long freq[1000001];
int main(void)
{   int l,r,n,i,p,j;
    scanf("%lld",&n);
    
        freq[0]=0;
        freq[1]=0;
    
        int prime[1000001]={0};
        prime[0]=prime[1]=1;
        for(i=2;i<=sqrt(1000001);i++)
        {
            if(prime[i]==0)
            for(p=i*i;p<=1000001;p+=i)
            prime[p]=1;
        }
    
    long count=0;
    for(i=2;i<=1000001;i++)
    {
        if(prime[i]==0)
        {
            count=i+count;
        }
      freq[i]=count;
    }
    while(n--)
    {
        scanf("%d %d",&l,&r);
        if(l==1)
        printf("%ld\n",freq[r]);
        else
        printf("%ld\n",freq[r]-freq[l-1]);
    }
    
    
}