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
    for(i=2;i<=1000;i++){
        if(a[i]!=0)continue;
        for(j=i*i;j<1000003;j+=i){
            a[j]=1;
        }
    }
    for(i=2;i<1000003;i++){
        if(a[i]!=0)a[i]=0;
        else a[i]=i;
    }
    for(i=3;i<1000003;i++){
        a[i]+=a[i-1];
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