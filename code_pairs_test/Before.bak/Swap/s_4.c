#include<stdio.h>
int main() {
	int a = 3;
	int b = 5;
	int temp;

	temp = a;
	a = b;
	b = temp;

	printf("The swapped numbers are %d and %d",a,b);
}
