#include <stdio.h>
int main(void) {
    int x,i,count,z=1;
    long long int a[10000000];
    scanf("%d",&x);
    while(x--)
    {
        scanf("%d",&count);
        z=1;
        for(i=1;i<=count;i++)
        scanf("%lld",&a[i]);
        
        for(i=1;i<count;i++)
        {
         if(a[i+1]>a[i]){
                    a[i+1] = a[i];
                }
                else z++;
        }
        printf("%d\n",z);
    }
	return 0;
}

