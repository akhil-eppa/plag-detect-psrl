#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp(const void *a,const void *b)
{ if(*(long int *)a-*(long int *)b>0)
    return 1;
  else return -1;
} 

int main(void) {
	// your code goes here
	int t,a,temp,gcd; 
	char b[255];
	scanf("%d",&t);
	while(t--)
	{ scanf("%d %s",&a,b);
	  temp = 0;
	  if(a==0)
	  {
	      printf("%s\n",b);
	      continue;
	  } 
	  int len = strlen(b);
	  for(int i=0; i<len;i++)
	  { temp = temp*10+b[i]-'0';
	    temp = temp%a;
	  }
	  gcd = a; 
	  while(temp>0)
	  { a=gcd;
	    gcd = temp;
	    temp = a%gcd;
	  }
	  printf("%d\n",gcd);
	} 
	return 0;
}

