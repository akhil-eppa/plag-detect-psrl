// pragma_directives_pack.cpp
#include <stddef.h>
#include <stdio.h>

typedef struct {
   int i;   // size 4
   short j;   // size 2
   double k;   // size 8
}S;

#pragma pack(2)
typedef struct {
   int i;
   short j;
   double k;
}T;

int main() {
   printf("%zu ", offsetof(S, i));
   printf("%zu ", offsetof(S, j));
   printf("%zu\n", offsetof(S, k));

   printf("%zu ", offsetof(T, i));
   printf("%zu ", offsetof(T, j));
   printf("%zu\n", offsetof(T, k));
}