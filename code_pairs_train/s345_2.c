#include  <stdio.h>
int main()
{
  long long int n,a,b,v,s=0,k,t,y;
  scanf("%llu",&t);
  for(y=0;y<t;y++)
  {
  scanf("%llu%llu%llu",&n,&a,&b);
  if(n%2!=0)
    {
    s=s+a;
    n--;
    }
  while(n>0)
  {
      v=n;
      n/=2;
      k=(v-n)*a;
      if(k>b)
        s=s+b;
      else
        s=s+k;
        if(n%2!=0)
        {
        n--;
        s=s+a;
        }
  }
  printf("%llu\n",s);
  s=0;
}
}