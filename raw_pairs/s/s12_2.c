 #include <stdio.h>
void foo(int *pointer) {
    *pointer=0;register char d=0;
    while(d<'0' || d>'9') {d=getchar();}
    while(d>='0' && d<='9') {*pointer=(*pointer<<1)+(*pointer<<3)+d-'0'; d=getchar();}
}
long ARRAY[1000005];
int main()
{
    int test_cases,left,right;
    foo(&test_cases);
    for(int i=2;i<=1000;i++){
        if(ARRAY[i]!=0)continue;
        for(int j=i*i;j<1000003;j+=i){
            ARRAY[j]=1;
        }
    }
    for(int i=2;i<1000003;i++){
        if(ARRAY[i]!=0)ARRAY[i]=0;
        else ARRAY[i]=i;
    }
    for(int i=3;i<1000003;i++){
        ARRAY[i]+=ARRAY[i-1];
    }
    ARRAY[1]=0;
    ARRAY[0]=0;
    while(test_cases--){
        foo(&left);
        foo(&right);
        printf("%ld\n",ARRAY[right]-ARRAY[left-1]);
    }
    return 0;
}