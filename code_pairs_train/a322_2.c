#include<stdio.h>
#include<string.h>
int rem(int i,char *b)
{   int remi,j,len;
    len=strlen(b);
    for(j=0;j<len;j++) b[j]-='0';
    remi=b[0]%i;
    for(j=1;j<len;j++)
    {
        remi=(remi*10+b[j])%i;
    }
    for(j=0;j<len;j++) b[j]+='0';
    return remi;
}
int hcf(int a,int b)
{if(b%a==0) return a;
return hcf(b%a,a);
}
int main()
{int t,w,i,j,a;
    char b[260];
    scanf("%d",&t);
    int out[t];
    for(w=0;w<t;w++){
        out[w]=1;
        scanf("%d",&a);
        scanf("%s",b);
        if(a==0 ) printf("%s\n",b);
        else{
        if(rem(a,b)==0) out[w]=a;
        else {out[w]=hcf(rem(a,b),a);}
        printf("%d\n",out[w]);}
        }
}
