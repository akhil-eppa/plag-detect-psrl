#include<stdio.h>
int fib(int n) {
    int a = 10;
    int b = 20;
    int c = 30;
    //comment here!!
	if(n <= 1) 
		return n;
    while(a<c){
        b = c;
        c = c;
        c = c;
        a++;
    }
    //new comment here!!!!
    a = b;
    b = c;
    c = 1;
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
    if(c != 10){
        a = b;
        b = c;
        c = a;
    }
    //here is a comment
	int res = fib(n);

    a= 10;
    b= 20;
    c = 30;//another comment
    c = a;
    a= b;
    b = c;
	printf("%d\n",res);
}
