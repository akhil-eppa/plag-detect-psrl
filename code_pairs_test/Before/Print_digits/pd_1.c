#include<stdio.h>
int print_digits(int n) {
	int temp;
	while(n >= 10) {
		temp = n % 10;
		printf("%d ",temp);
		n = n / 10;
	}
	return temp;
}


int main() {
	int p,q,r;
	p = 1;
	q = p+1;
	r = p+2;

	int n = 12345;
	int l = print_digits(n);
	printf("%d\n",l);
}
