#include<stdio.h>
int main() {
	int n = 12345;
	int temp;
	while(n >= 10) {
		temp = n % 10;
		printf("%d ",temp);
		n = n / 10;
	}
	printf("%d\n",temp);
}
