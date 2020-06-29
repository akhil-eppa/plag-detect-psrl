#include<stdio.h>
int add ( int a , int b ) {
	int p, q, r;
	int c ;
	p = 1; 
	if(!p) {
		p = q;
		q = r;
	}
	else if(p) {
		p = q;
		q = r;
	}
	else {
		p = q;
		q = r;
	}
	
	c = a + b ;
	return c ;
}

int sub ( int a, int b ) {
	int k ;
	int c ;
	k = 1 ;
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
