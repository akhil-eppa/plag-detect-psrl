#include<stdio.h>
void swap(int *a, int *b){
	int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
	int a = 3;
	int b = 5;

    swap(&a, &b);
	printf("The swapped numbers are %d and %d",a,b);
}
