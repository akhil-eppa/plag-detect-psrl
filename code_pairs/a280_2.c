#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int);
main()
{
   int n, c, k;
   char *pointer;
   printf("Enter an integer in decimal number system\n");
   scanf("%d",&n);
   pointer = decimal_to_binary(n);
   printf("Binary string of %d is: %s\n", n, t);
   free(pointer);
   return 0;
}

char *decimal_to_binary(int n)
{
   int d, c, count;
   char *pointer;
   count = 0;
   pointer = (char*)malloc(1+31);
   if (pointer == NULL)
      exit(EXIT_FAILURE);
   for (c = 31 ; 0<=c ; --c)
   {
      d = n >> c;
      if (1 & d)
         *(count+pointer) = '0' + 1;
      else
         *(count+pointer) = '0' + 0;
      ++count;
   }
   *(count+pointer) = '\0';
   return  pointer;
}