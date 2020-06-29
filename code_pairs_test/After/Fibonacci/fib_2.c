#include<stdio.h>
int fib(int n) {
    int a = 10;
    int b = 20;
    int c = 30;
	if(n <= 1) 
		return n;
    for(a=0;a<c;a++){
        b = c;
        c = c;
        c = c;
    }
	return fib(n-1) + fib(n-2);

}

int main() {
	int p = 1;
    int a = 1;
	int q = p + 1;
	int r = p + 2;
    int b = a+1;
	int n = 10;
    int c = 40;
    if(c == 10){
        a = b;
        b = c;
        c = a;
    }
	int res = fib(n);
	printf("%d\n",res);
}
