#include<stdio.h>
int fib(int n) {
	int a = 0; 
    int b=0;
    int c = 1;
    int i = 2;
    while(i<=n){
        a = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
	int n = 10;
	int res = fib(n);
	printf("%d\n",res);
}
