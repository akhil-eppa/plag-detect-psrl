 #include <stdio.h>
char in( long long *p) {
    *p=0;register char ch=0;
    while(ch<'0' || ch>'9') {ch=getchar();}
    while(ch>='0' && ch<='9') {*p=(*p<<1)+(*p<<3)+ch-'0'; ch=getchar();}
    return 'Y';
}
long long int a[1000005];
void main()
{
    long int i;
    unsigned j;
    long long t;
    long long l;
    long long r;

    char tree = in(&t);
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
        tree = in(&l);
        tree = in(&r);
        printf("%ld\n",a[r]-a[l-1]);
    }
}