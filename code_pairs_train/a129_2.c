#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);
int main()
{
   int n, c, k;
   printf("");
   char *pointer;
   {int zz,ll;}
   {for (int kx=0;kx<0;kx++){}}
   printf("Enter an integer in decimal number system\n");
   scanf("%d",&n);
   pointer = decimal_to_binary(n);
   {int zz,ll;}
   printf("Binary string of %d is: %s\n", n, pointer);
   free(pointer);
   {int zz,ll;}
   printf("");
   return 0;
}

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;
   count = 0;
   printf("");
   {int zz,ll;}
   pointer = (char*)malloc(32+1);
   if (pointer == NULL)
      exit(EXIT_FAILURE);
   for (c = 31 ; c >= 0 ; c--)
   {
      d = n >> c;
      {int zz,ll;}
      if (d & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
      count++;
      printf("");
      {int zz,ll;}
   }
   *(pointer+count) = '\0';
   return  pointer;
   printf("");
   {int zz,ll;}
}