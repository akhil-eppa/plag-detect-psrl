#include<stdio.h>
int add ( int a , int b ) {
	int c ;
	c = a + b ;
	return c ;
}

int sub ( int a, int b ) {
	int c ;
	c = a - b ;
	return c ;
}

int main() {
	int a = 10;
	int b = 15;
	int c = add(a,b);
	int d = sub(a,b);
	printf("%d %d\n",c,d);
}
