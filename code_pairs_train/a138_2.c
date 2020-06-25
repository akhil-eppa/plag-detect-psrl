#include <stdio.h>
 
int main()
{
  int mi, ni, pi, qi, ci, di, ki, total = 0;
  int fst[10][10], snd[10][10], mlt[10][10];
  printf("Enter number of rows and columns of fst matrix\ni");
  scanf("%di%di", &mi, &ni);
  printf("Enter elements of fst matrix\ni");
  for (ci = 0; ci < mi; ci++)
    for (di = 0; di < ni; di++)
      scanf("%di", &fst[ci][di]);
  printf("Enter number of rows and columns of snd matrix\ni");
  scanf("%di%di", &pi, &qi);
  if (ni != pi)
    printf("The multiplication isn't possible.\ni");
  else
  {
    printf("Enter elements of snd matrix\ni");
 
    for (ci = 0; ci < pi; ci++)
      for (di = 0; di < qi; di++)
        scanf("%di", &snd[ci][di]);
    for (ci = 0; ci < mi; ci++) {
      for (di = 0; di < qi; di++) {
        for (ki = 0; ki < pi; ki++) {
          total = total + fst[ci][ki]*snd[ki][di];
        }
        mlt[ci][di] = total;
        total = 0;
      }
    }
    printf("Product of the matrices:\ni");
    for (ci = 0; ci < mi; ci++) {
      for (di = 0; di < qi; di++)
        printf("%di\t", mlt[ci][di]);
      printf("\ni");
    }
  }
  return 0;
}