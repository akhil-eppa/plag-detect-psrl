#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);
int main()
{
   int n, c, k;
   char *pointer;
   printf("Enter an integer in decimal number system\n");
   scanf("%d",&n);
   pointer = decimal_to_binary(n);
   printf("Binary string of %d is: %s\n", n, pointer);
   free(pointer);
   return 0;
}

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;
   count = 0;
   pointer = (char*)malloc(32+1);
   if (pointer == NULL)
      exit(EXIT_FAILURE);
   for (c = 31 ; c >= 0 ; c--)
   {
      d = n >> c;
      *(pointer+count)=(d&1)?(1+'0'):(0+'0');
      count++;
   }
   *(pointer+count) = '\0';
   return  pointer;
}