#include <stdio.h>
 
int main()
{int l,r,k,i,count;
    scanf("%d ",&l);
    scanf("%d ",&r);
    scanf("%d ",&k);
 for (i=l;i<=r;i++){
 	if(i%k==0){
 	count++;	
 	} 
 	else count = count;
 }
 printf("%d",count);
}