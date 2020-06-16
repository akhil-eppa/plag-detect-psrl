#include<stdio.h>
#include<string.h>
void sort(long l, long h, long long [], long long []);
void merge(long l, long m, long h, long long [], long long []);
int main()
{
    char a[100001];
    long t, p, i, f;
    scanf("%ld", &t);
    
 
    long long sum, temp;
    for(;t>0;t--)
    {
        
        scanf("%s", &a);
        p=strlen(a);
        long long s[p+1], r[p+1];
        s[0]=0;
        for(i=0; i<p; i++)
        {
            sum=a[i]-97;
            sum=(1<<sum);
            s[i+1]=s[i]^sum;
            
            
        }
        
        sort(0, p, s, r);
        sum=0;
        for(i=0; i<=p;)
        {
            f=0;
            temp=s[i];
            while(s[i]==temp)
            {
                f++;
                i++;
            }
            sum=sum+((f)*(f-1))/2;
        }
        
        printf("%lld\n", sum);
        
    }
}
 
 
void sort(long l, long h, long long a[], long long b[])
{
    if(l<h)
    {
        long m=(l+h)/2;
        sort(l, m, a, b);
        sort(m+1, h, a, b);
        merge(l, m, h, a, b);
    }
}
 
void merge(long l, long m, long h, long long a[], long long b[])
{
    long i=l, k=l, j=m+1;
    
    while(k<=h)
    {
        if(i<=m && j<=h)
        {
            if(a[i]<=a[j])
            {
                b[k]=a[i];
                k++;
                i++;
            }
            else
            {
                b[k]=a[j];
                j++;
                k++;
            }
        }
        else if(i>m)
        {
            b[k]=a[j];
            k++;
            j++;
        }
        else
        {
            b[k]=a[i];
            k++;
            i++;
        }
    }
    for(i=l; i<=h; i++)
    {
        a[i]=b[i];
    }
}