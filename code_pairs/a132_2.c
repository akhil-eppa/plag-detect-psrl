#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);
int main()
{
   printf("Enter an integer in decimal number system\n");
   char *pointer;
   int n, c, k;
   scanf("%d",&n);
   pointer = decimal_to_binary(n);
   printf("Binary string of %d is: %s\n", n, pointer);
   free(pointer);
   return 0;
}

char *decimal_to_binary(int n)
{
   char *pointer;
   pointer = (char*)malloc(32+1);
   int c, d, count;
   count = 0;
   if (pointer == NULL)
      exit(EXIT_FAILURE);
   for (c = 31 ; c >= 0 ; c--)
   {
      d = n >> c;
      if (d & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
      count++;
   }
   *(pointer+count) = '\0';
   return  pointer;
}