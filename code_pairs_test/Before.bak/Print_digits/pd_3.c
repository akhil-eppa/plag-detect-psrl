#include<stdio.h>
int DigitPrinter(int num) {
	int digit;
	while(num >= 10) {
		digit = num % 10;
		printf("%d ",digit);
		num = num / 10;
	}
	return digit;
}


int main() {
	int num = 12345;
	int l_digit = DigitPrinter(num);
	printf("%d\n",l_digit);
}
