 #include <stdio.h>
 #define MAX 1000005
 #define ZERO '0'
void in(int *p) {
    *p=0;register char ch=0;
    while(ch<ZERO || ch>ZERO+9) {ch=getchar();}
    while(ch>=ZERO && ch<=ZERO+9) {*p=(*p<<1)+(*p<<3)+ch-ZERO; ch=getchar();}
}
long a[MAX];
int main()
{
    int i,j,t,l,r;
    in(&t);
    for(i=2;i<=1000;i++){
        if(a[i]!=0)continue;
        for(j=i*i;j<MAX-2;j+=i){
            a[j]=1;
        }
    }
    for(i=2;i<MAX-2;i++){
        if(a[i]!=0)a[i]=0;
        else a[i]=i;
    }
    for(i=3;i<MAX-2;i++){
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