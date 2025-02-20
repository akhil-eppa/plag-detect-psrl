#include<stdio.h>

void swap(unsigned int a[], int i, int j)	// interchange a[i] and a[j]
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(unsigned int a[], int s, int e)	// partition a[s] to a[e]
{
	int l;	// l denotes last element of left partition
	int i;

	swap(a, s, (s + e) / 2);	// move pivot from middle to 0
	l = s;	// set size of left partition to 0

	for (i = s + 1; i <= e; i++)	// examine all elements
		if (a[i] < a[s])	// a[i] should go to left partition
		{
			l++;	// make left partition larger by incrementing l
			swap(a, l, i);	// move a[i] to left partition
		}

	swap(a, s, l);	// put pivot to its correct position l

	return l;	// return demarcation of partitions
}

void quicksort(unsigned int a[], int s, int e)	// sort a[s] to a[e]
{
	int l;

	if (s >= e)	// array contains 0 or 1 element
		return;	// array is already sorted

	l = partition(a, s, e);	// partition

	quicksort(a, s, l - 1);	// sort left partition
	quicksort(a, l + 1, e);	// sort right partition
}
int main(){
	int t,n,i;
	unsigned int min;
	scanf("%d",&t);
	while(t--){
		min=999999999;
		scanf("%d",&n);
		unsigned int x[n];
		for(i=0;i<n;i++){
			scanf("%u",&x[i]);
		}
		quicksort(x,0,n-1);
		for(i=1;i<n;i++){
			if(x[i]-x[i-1]<min){
				min=x[i]-x[i-1];
			}
		}
		printf("%d\n",min);
		
	}
	return 0;
}