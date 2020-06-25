// pragma_directives_pack.cpp
#include <stddef.h>
#include <stdio.h>

struct S {
   int i;   // size 4
   short j;   // size 2
   double k;   // size 8
};

#pragma pack(2)
struct T {
   int i;
   short j;
   double k;
};

int main() {
   printf("%zu ", offsetof(struct S, i));
   printf("%zu ", offsetof(struct S, j));
   printf("%zu\n", offsetof(struct S, k));

   printf("%zu ", offsetof(struct T, i));
   printf("%zu ", offsetof(struct T, j));
   printf("%zu\n", offsetof(struct T, k));
}
