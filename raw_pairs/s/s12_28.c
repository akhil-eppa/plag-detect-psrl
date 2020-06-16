#include<stdio.h>
#define mod 1000000007
int cmp(const void * a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main(){
	int n,i,c;
    scanf("%d",&n);
    long pow2[n],a[n],x,res=0;
    pow2[0]=1;
    for(i=1;i<n;i++)
    pow2[i]=(pow2[i-1]<<1)%mod;
    for(i=0;i<n;i++)
    scanf("%ld",&a[i]);
    qsort(a,n,sizeof(long),cmp);
    i=0;
    while(i<n)
    {
        x=a[i];
        c=0;
        while(i<n && a[i]==x)
        {
            c++;
            i++;
        }
        if(x)
            res+=pow2[c-1];
        else
            res+=pow2[c]-1;
        res%=mod;
    }
    printf("%ld",res);
}