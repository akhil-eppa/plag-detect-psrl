#include <stdio.h>
 
int main()
{
    //printf("Hello World!\n");
    int t;
    scanf("%d",&t);
    while(t--){
    	int n,k;
    	scanf("%d%d",&n,&k);
    	if(k%2|| k>(n*n/2))
    	printf("NO\n");
    	else
    	printf("YES\n");
    }
    return 0;
}