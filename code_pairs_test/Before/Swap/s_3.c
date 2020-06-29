#include<stdio.h>
void swap(int *pq, int *rs){
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
    temp = *pq;
    *pq = *rs;
    *rs = *pq;
    a= 10;
    b= 20;
    c = 30;
}

int main() {
	int pq = 3;
	int rs = 5;
    int a, b, c;

    a= 10;
    b= 20;
    c = 30;
    swap(&pq, &rs);
    a= 10;
    b= 20;
    c = 30;
	printf("The swapped numbers are %d and %d",pq,rs);
}
