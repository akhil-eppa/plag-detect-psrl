#include <stdio.h>

#define ln 1000000

int tree[1<<21];
int ind[ln+1];


int search(int x,int id, int l, int r)
{
	if(l==r)
	{
		tree[id] -= 1;
		update(id);
		return l;
	}

	int mid = (l+r)/2;

	if(tree[id*2] >= x) return search(x,id*2,l,mid);
	else return search(x-tree[id*2], id*2+1, mid+1, r);

}

void initialize(int id, int l, int r)
{
	if(l == r)
	{
		return;
	}

	int mid = (l+r)/2;
	initialize(id*2, l, mid);
	initialize(id*2 + 1, mid+1, r);
	tree[id] = tree[id*2] + tree[id*2 + 1];
	return;
}

void update(int n)
{
	int p = n/2;

	if(p < 1) return;

	tree[p] = tree[p*2] + tree[p*2 + 1];
	update(p);
}

void build_segment_tree(int id, int l, int r)
{
	if(l == r)
	{
		ind[l] = id;
		return;
	}

	int mid = (l+r)/2;
	build_segment_tree(id*2, l, mid);
	build_segment_tree(id*2 + 1, mid+1, r);

	return;
}



int main()
{
	// freopen("input.txt", "r", stdin);
	int n, q, x;
	scanf("%d %d", &n, &q);

	build_segment_tree(1, 1,ln);

	for(int i=0; i<n; i++)
	{
		scanf("%d", &x);
		tree[ind[x]] += 1;
	}

	initialize(1, 1, ln);

	for(int i=0; i<q; i++)
	{
		scanf("%d", &x);

		if(x > 0)
		{
			tree[ind[x]] += 1;
			update(ind[x]);
		}

		else
		{
			x *= -1;
			search(x,1,1,ln);
		}

	}

	if(!tree[1]) printf("0\n");
	else printf("%d\n", search(1,1,1,ln));
	return 0;
}
