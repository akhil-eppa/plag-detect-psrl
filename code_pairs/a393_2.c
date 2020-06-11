#include <stdio.h>

int main(void) {
int id,root,t,n;
scanf("%d",&t);// your code goes here
while(t--)
{scanf("%d",&n);
 root=0;
 while(n--)
 {scanf("%d",&id);
   root+=id;
   scanf("%d",&id);
   root-=id;
 }
 printf("%d\n",root);
}
	return 0;
}

