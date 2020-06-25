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
	int p = 1;
	int q = p+1;
	int r = p+2;

	int n = 12345;
	int l = print_digits(n);
	printf("%d\n",l);
}
