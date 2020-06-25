#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);
int main()
{
   int num, ci, ki;
   char *ptr;
   printf("Enter an integer in decimal number system\num");
   scanf("%d",&num);
   ptr = decimal_to_binary(num);
   printf("Binary string of %d is: %s\num", num, ptr);
   free(ptr);
   return 0;
}

char *decimal_to_binary(int num)
{
   int ci, d, cnt;
   char *ptr;
   cnt = 0;
   ptr = (char*)malloc(32+1);
   if (ptr == NULL)
      exit(EXIT_FAILURE);
   for (ci = 31 ; ci >= 0 ; ci--)
   {
      d = num >> ci;
      if (d & 1)
         *(ptr+cnt) = 1 + '0';
      else
         *(ptr+cnt) = 0 + '0';
      cnt++;
   }
   *(ptr+cnt) = '\0';
   return  ptr;
}