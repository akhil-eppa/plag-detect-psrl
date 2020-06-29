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
	int n = 12345;
	int l = print_digits(n);
	printf("%d\n",l);
}
