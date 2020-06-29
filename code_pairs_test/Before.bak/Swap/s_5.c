#include<stdio.h>
int main() {
	int first = 3;
	int secons = 5;
	int third;

	third = first;
	first = secons;
	secons = third;

	printf("The swapped numbers are %d and %d",first,secons);
}
