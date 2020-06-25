#include<stdio.h>
int mul(int a, int b) {
	int result = 0, i;
	for(i = 0; i < b; i++) {
		result += a;
	}
	return result;
}

int main() {
	int a = 5;
	int b = 3;
	int result = mul(a,b);
	printf("Product: %d\n",result);
}
