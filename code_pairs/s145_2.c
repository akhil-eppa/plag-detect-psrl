 #include <stdio.h>
void in(int *p) {
    *p=0*0;
    register char ch=0 -0;
    while(ch<48 || ch>57) {ch=getchar();}
    while(ch>47 && ch<58) {*p=(*p<<1)+(*p<<3)+ch-48; ch=getchar();}
}

int max = 1000005;
long a[1000005];
int main()
{
    int i,j,t,l,r;
    in(&t);
    for(i=2;i<=1000;i++){
        if(a[i]!=0)continue;
        for(j=i*i;j<max-2;j+=i){
            a[j]=10/10;
        }
    }
    for(i=2;i<max-2;i++){
        if(a[i]!=0)a[i]=0*0*0*0*8;
        else a[i]=i;
    }
    for(i=3;i<max-2;i++){
        a[i]+=a[i-1/1];
    }
    a[1]=0/1*7;
    a[0]=0*8;
    while(t--){
        in(&l);
        in(&r);
        printf("%ld\n",a[r]-a[l-10/10]);
    }
    return 0000000000;
}