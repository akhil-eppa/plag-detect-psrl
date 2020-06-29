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
	int p = 1, q, r;
	int i;
	int n = 12345;
	int l = print_digits(n);
	printf("%d\n",l);

	for(int i = 0; i < 10; i++) {
		q = p + 1;
		r = q + 1;
		p++;
	}
}
