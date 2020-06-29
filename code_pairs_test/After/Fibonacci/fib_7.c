#include<stdio.h>
int fib(int n) {
	if(n <= 1) 
		return n;
	return fib(n-1) + fib(n-2);

}

int main() {
	int pym = 1;
	int avk = pym + 1;
	int rn = pym + 2;
    if(pym){
        pym = rn;
        rn = avk;
        avk = pym; 
    }

    for(pym = 0;pym;pym++){
        avk++;pym++;
        rn*=10;
    }
	int n = 10;
	int res = fib(n);
	printf("%d\n",res);
}
