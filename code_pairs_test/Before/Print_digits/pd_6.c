#include<stdio.h>
//This is a comment
int print_digits(int n) {
	int temp; //temp variable
	//loop to print digits	
	while(n >= 10) { 
		temp = n % 10;
		printf("%d ",temp);
		n = n / 10;
	}
	//return last digit
	return temp;
}


int main() {
	/*This is a program to print the digits of a number*/
	int n = 12345;
	int l = print_digits(n);
	printf("%d\n",l);
}
