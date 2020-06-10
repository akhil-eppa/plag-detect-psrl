#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);
int main()
{
   int n, c, k;
   char *ptr;
   printf("Enter an integer in decimal number system\n");
   scanf("%d",&n);
   ptr = decimal_to_binary(n);
   printf("Binary string of %d is: %s\n", n, ptr);
   free(ptr);
   return 0;
}

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *ptr;
   count = 0;
   ptr = (char*)malloc(32+1);
   if (ptr == NULL)
      exit(EXIT_FAILURE);
   for (c = 31 ; c >= 0 ; c--)
   {
      d = n >> c;
      if (1 & d)
         *(ptr+count) = 1 + '0';
      else
         *(ptr+count) = 0 + '0';
      count++;
   }
   *(ptr+count) = '\0';
   return  ptr;
}