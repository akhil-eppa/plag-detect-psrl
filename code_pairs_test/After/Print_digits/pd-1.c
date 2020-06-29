#include<stdio.h>
void print_digits(int n) {
	if(n == 0)
		return;
	int temp = n % 10;
	print_digits(n/10);
	printf("%d ",temp);
}


int main() {
	int n = 12345;
	print_digits(n);
}
