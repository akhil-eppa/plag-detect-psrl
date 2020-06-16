#include<stdio.h> 
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
   unsigned long  int n,m,k,i,j;
    scanf("%lu %lu %lu",&n,&m,&k);
    unsigned long  int p=n*m;
    unsigned long int z[n],y[p];
    for(i=0;i<n;i++)
    {
    scanf("%lu",&z[i]);
    }
    for(i=0;i<p;i+n)
    {
        for(j=0;j<n;j++)
        {
            y[i]=z[j];
            i++;
        }
    }
   unsigned long  int temp=0,x=0; 
   for (i=0; i<p; i++) 
    { 
        temp=0; 
        for (j=i; j<p; j++) 
        { 
            temp+=y[j]; 
            if(temp<=k)
            x++;
        } 
    }
   printf("%lu\n",x%1000000007);
 }
    return 0; 
} 