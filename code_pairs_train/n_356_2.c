#include <stdio.h>

#define ln 1000000

int tree_struct[1 << 21];
int indexarray[ln + 1];

void segment_tree(int id, int l, int r) {
  if (l == r) {
    indexarray[l] = id;
    return;
  }

  int middle = (l + r) / 2;
  segment_tree(id * 2, l, middle);
  segment_tree(id * 2 + 1, middle + 1, r);

  return;
}

void init(int id, int l, int r) {
  if (l == r) {
    return;
  }

  int mid = (l + r) / 2;
  init(id * 2, l, mid);
  init(id * 2 + 1, mid + 1, r);
  tree_struct[id] = tree_struct[id * 2] + tree_struct[id * 2 + 1];
  return;
}

void update(int n)
{
	int p = n/2;

	if(p < 1) return;

        tree_struct[p] = tree_struct[p * 2] + tree_struct[p * 2 + 1];
        update(p);
}

int search(int x,int id, int l, int r)
{
	if(l==r)
	{
          tree_struct[id] -= 1;
          update(id);
          return l;
	}

	int mid = (l+r)/2;

        if (tree_struct[id * 2] >= x)
          return search(x, id * 2, l, mid);
        else
          return search(x - tree_struct[id * 2], id * 2 + 1, mid + 1, r);
}


int main()
{
	// freopen("input.txt", "r", stdin);
        int num, q, var2;
        scanf("%d %d", &num, &q);

        segment_tree(1, 1, ln);

        for (int i = 0; i < num; i++) {
          scanf("%d", &var2);
          tree_struct[indexarray[var2]] += 1;
        }

        init(1, 1, ln);

        for(int i=0; i<q; i++)
	{
          scanf("%d", &var2);

          if (var2 > 0) {
            tree_struct[indexarray[var2]] += 1;
            update(indexarray[var2]);
          }

          else {
            var2 *= -1;
            search(var2, 1, 1, ln);
          }
        }

        if (!tree_struct[1])
          printf("0\n");
        else printf("%d\n", search(1,1,1,ln));
	return 0;
}
