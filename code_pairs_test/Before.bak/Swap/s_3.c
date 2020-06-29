#include<stdio.h>
void swap(int *a, int *b){
	int temp;
    int a, b, c;

    a= 10;
    b= 20;
    c = 30;

    if(a!=10){
        a = b;
        b = c;
        c = a;
        a++;
        b++;
        c++;
        a--;
        b--;
        c--;
    }
    temp = *a;
    *a = *b;
    *b = temp;
    a= 10;
    b= 20;
    c = 30;
}

int main() {
	int a = 3;
	int b = 5;
    int a, b, c;

    a= 10;
    b= 20;
    c = 30;
    swap(&a, &b);
    a= 10;
    b= 20;
    c = 30;
	printf("The swapped numbers are %d and %d",a,b);
}
