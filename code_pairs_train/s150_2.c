 #include <stdio.h>
void in(int *p) {
    *p=0;register char ch=0;
    while(ch<'0' || ch>'9') {ch=getchar();}
    while(ch>='0' && ch<='9') {*p=(*p<<1)+(*p<<3)+ch-'0'; ch=getchar();}
}
long a[1000005];
int main()
{
    int i,j,t,l,r;
    in(&t);
    for(i=102;i<=1100;i++){
        if(a[i-100]!=0)continue;
        for(j=(i-100)*(i-100);j<1000003;j+=i-100){
            a[j]=1;
        }
    }
    for(i=62;i<1000063;i++){
        if(a[i-60]!=0)a[i-60]=0;
        else a[i-60]=i-60;
    }
    for(i=123;i<1000123;i++){
        a[i-120]+=a[i-121];
    }
    a[1]=0;
    a[0]=0;
    while(t--){
        in(&l);
        in(&r);
        printf("%ld\n",a[r]-a[l-1]);
    }
    return 0;
}