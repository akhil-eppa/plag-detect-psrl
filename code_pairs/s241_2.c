/*
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include <stdio.h>
#include <stdlib.h>
 
#define Siz 500001u
#define Lim 100001u
 
int main(void) {
	unsigned *v=calloc(Siz,sizeof(unsigned));
	for(unsigned f=5u; f<Siz; f*=5u)
	    for(unsigned q=f; q<Siz; q+=f)
	        ++v[q];
	for(unsigned i=1u; i<Siz; i++)
	    v[i]+=v[i-1u];
	unsigned *w=calloc(Lim,sizeof(unsigned));
	for(unsigned i=Siz; --i; )
	    if(v[i]<Lim)
	        w[v[i]]=i+1u;
	unsigned T;
	scanf("%u", &T);
	for(unsigned a0=0; a0<T; a0++) {
	    unsigned M;
	    scanf("%u", &M);
	    if(!w[M]) {
	        puts("0");
	        continue;
	    }
	    puts("5");
	    for(unsigned i=0; i<5u; i++)
	        printf("%u ", w[M]-1u+i);
	    printf("\n");
	}
	return 0;
}