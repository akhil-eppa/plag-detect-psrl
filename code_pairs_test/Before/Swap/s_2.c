#include<stdio.h>
int main() {
	int pq = 3;
	int rs = 5;
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

	temp = pq;
	pq = rs;
	rs = temp;   

    a = 10;
    b = 20;
    c = 30;

	printf("The swapped numbers are %d and %d",pq,rs);
}
