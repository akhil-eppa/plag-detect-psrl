#include <stdio.h>
#include <math.h>
int table[10000],value,value2,value3,value4,N,T,i,k;
double end;
int check(int qweqwe);
int main()
{
	table[0]=0;
	table[1]=0;
   for(i=3;i<=10000;i=i+2){
   	k=i*i;
   	value=check(k);
   	k=k-(i-1);
   	value2=check(k);
   	k=k-(i-1);
   	value3=check(k);
   	k=k-(i-1);
   	value4=check(k);
   	table[i]=table[i-2]+value+value2+value3+value4;
   }
   scanf("%d",&T);
   while(T--){
   	scanf("%d",&N);
   	end=table[N]*(100.0);
   	end=end/((2*N)-1);
   	printf("%.6f\n",end);
   }
    return 0;
}
int check(int x){
    int i;
 
    if (x==2 || x==3)
        return 1;
 
    if (x%2==0 || x==1)
        return 0;
 
    for (i=3;i<=sqrt(x);i+=2)
        if (x%i==0)
            return 0;
 
    return 1;
}