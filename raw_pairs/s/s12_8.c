 #include <stdio.h>
void in(int *p) {
    *p=0;register char ch;
    for(ch = 0;ch<'0' || ch>'9';) 
    {
        ch=getchar();
    }
    for(;ch>='0' && ch<='9';)
     {
         *p=(*p<<1)+(*p<<3)+ch-'0'; 
         ch=getchar();
     }
}
long a[1000005];
int main()
{
    int i = 2,j,t,l,r;
    in(&t);
    for(;i<1001;++i)
    {
        j = i * i;
        if(a[i]!=0)
            continue;
        while(j<1000003){
            a[j]=1;
            j = j + i;
        }
        
    }
    i = 2;
    while(i<1000003){
        if(a[i]!=0)a[i]=0;
        else a[i]=i;
        ++i;
    }
    i = 3;
    while(i<1000003){
        a[i]+=a[i-1];
        ++i;
    }
    a[1]=0;
    a[0]=0;
    for(i = 0; i<t;i++){
        in(&l);
        in(&r);
        printf("%ld\n",a[r]-a[l-1]);
    }
    return 0;
}