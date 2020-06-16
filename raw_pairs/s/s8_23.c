#include <stdio.h>
#include <string.h>
int main()
{
  char a[100];
  int length,i,X,Y,count=0;
 
    scanf("%s",&a);
 
  length = strlen(a);
  
  for(i=0;i<length;i++)
  {
      if(a[i]=='z')
      {
          count++;
      }
  }
  Y=length-count;
  X=count*2;
  if(Y==X)
  {
      printf("Yes");
  }
  else
  {
      printf("No");
  }
 
   return 0;
}
