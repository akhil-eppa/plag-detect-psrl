#include<stdio.h>

int main() {
	int n = 10;
	int a = 0; 
    int b=0;
    int c = 1;
    int i = 2;
    while(i<=n){
        a = a+b;
        a = b;
        b = c;
    }
	printf("%d\n",c);
}
