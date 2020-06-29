#include<stdio.h>
int fib(int n) {
	if(n <= 1) 
		return n;
	return fib(n-1) + fib(n-2);

}

int main() {
	int pym = 1;
	int avk = pym + 1;
	int rn = pym + 2;

	int n = 10;
	int res = fib(n);
	printf("%d\n",res);
}
