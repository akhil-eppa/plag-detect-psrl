#include<stdio.h>
int mul(int a, int b) {
	int res = 0, i;
	for(i = 0; i < b; i++) {
		res += a;
	}
	return res;
}

int main() {
	int a = 5;
	int b = 3;
	int res = mul(a,b);
	printf("Product: %d\n",res);
}
