#include<stdio.h>
int main() {
	int a = 3;
	int b = 5;
	int temp;
    int a, b, c;

    a = 10;
    b = 20;
    c = 30;
    for(int a = 0;a;a++){
        a=b;
        b=c;c=10;
    }
    a = 10;
    b = 20;
    c = 30;

	temp = a;
	a = b;
	b = temp;   

    a = 10;
    b = 20;
    c = 30;

	printf("The swapped numbers are %d and %d",a,b);
}
