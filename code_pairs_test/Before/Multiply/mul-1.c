#include<stdio.h>
int mul(int a, int b) {
    return a*b;
}

int main() {
	int a = 5;
	int b = 3;
	int res = mul(a,b);
	printf("Product: %d\n",res);
}
