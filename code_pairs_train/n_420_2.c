#include<stdio.h>
#include<stdlib.h>

int h[100005];

int cmpfn(const void *_a, const void *_b){
	int *a = (int *)_a;
	int *b = (int *)_b;
	return (*a) - (*b);
}

int main(){
  int one, two, three, four;
  long long answer;
  scanf("%d %d %d %d", &one, &two, &three, &four);
  if (one == 1) {
    printf("0\n");
    return 0;
  }
  if (four > two + three)
    four = two + three;
  int i;
  for (i = 0; i < one; i++)
    scanf("%d", h + i);
  qsort(h, one, sizeof(int), cmpfn);
  long long sumLeft, total;
  for (i = 0, total = 0; i < one; i++)
    total += h[i];
  answer = total * three;
  sumLeft = 0;
  for (i = 0; i < one - 1; i++) {
    long long addL, addR, delL, delR;
    sumLeft += h[i];
    addL = (i + 1) * 1ll * h[i] - sumLeft;
    addR = (i + 1) * 1ll * h[i + 1] - sumLeft;
    delL = (total - sumLeft) - (one - (i + 1)) * 1ll * h[i];
    delR = (total - sumLeft) - (one - (i + 1)) * 1ll * h[i + 1];
    long long movL, movR;
    movL = addL < delL ? addL : delL;
    movR = addR < delR ? addR : delR;

    long long costL, costR;
    costL = (addL - movL) * 1ll * two + (delL - movL) * 1ll * three +
            movL * 1ll * four;
    costR = (addR - movR) * 1ll * two + (delR - movR) * 1ll * three +
            movR * 1ll * four;
    if (answer > costL)
      answer = costL;
    if (answer > costR)
      answer = costR;

    // meeting point
    if (addL <= delL && addR >= delR) {
      int x = total / one;
      if (x >= h[i] && x <= h[i + 1]) {
        long long add, del, mov;
        add = (i + 1) * 1ll * x - sumLeft;
        del = (total - sumLeft) - (one - (i + 1)) * 1ll * x;
        mov = add < del ? add : del;
        long long cost = (add - mov) * 1ll * two + (del - mov) * 1ll * three +
                         mov * 1ll * four;
        if (answer > cost)
          answer = cost;
      }
      x++;
      if (x >= h[i] && x <= h[i + 1]) {
        long long add, del, mov;
        add = (i + 1) * 1ll * x - sumLeft;
        del = (total - sumLeft) - (one - (i + 1)) * 1ll * x;
        mov = add < del ? add : del;
        long long cost = (add - mov) * 1ll * two + (del - mov) * 1ll * three +
                         mov * 1ll * four;
        if (answer > cost)
          answer = cost;
      }
    }
        }
        printf("%lld\n", answer);
        return 0;
}
