#include <stdio.h>
#include <math.h>
 
int lp[1500],npl[5000];
 
int isprime(int n)
{
  int k,sk=sqrt(n);
      for(k=3;k<sk;k+=2)
      {
        if(n%k==0)
          return 0;
      }
   return 1;
}
 
int isprime1(int n)
{
  int k,sk=sqrt(n);
      for(k=0;lp[k]<sk;k++)
      {
        if(n%lp[k]==0)
          return 0;
      }
   return 1;
}
 
 
int main() 
{
  int t,s,i,j,k,n=0,si[100000],tp=0,tn;
  double p,temp;
  for(i=3;i<11000;i+=2)
  {
    if(isprime(i))
    lp[n++]=i;
  }
  npl[0]=0;
  for(i=3;i<10000;i+=2)
  {
    int m=0;
    for(k=3;k>0;k--)
    m+=isprime1(i*i-k*(i-1));
    npl[(i-1)/2]=npl[(i-3)/2]+m;  
  }
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    tp=0,n=0;
    scanf("%d",&s);
    tp=npl[(s-1)/2];
    tn=2*s-1;
 //printf("%d %d\n",tp,tn);
  temp=tp;
  p=temp*100/tn;
  printf("%lf\n",p);
  }
  getchar();
  //getchar();
  return 0;
}