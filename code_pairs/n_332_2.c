#include<stdio.h>
#define max(a,b) ((a>b)?(a):(b))

long long ways[1000006];

int main() {
	int a,b,c,d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int tx = b - a, ty = c - b, lz = c - a - b, rz = d - a - b;
	long long ans = 0;
	for( int z=0; z<=rz; ++z ) {
		int l=0, r=z;
		r = (r>tx)?tx:r;
		// ( z - r, z - l )
		if( z - l > ty )
			l = z - ty;
		ways[z] = max(0, r - l + 1);
		if( z > 0 )
			ways[z] += ways[z-1];
	}
	int z = max(0,lz);
	while(z<=lz){
		ans += ways[z];
		++z;
	}
	printf("%lld\n", (((1ll*(b-a+1))*(c-b+1))*(d-c+1)) - ans);
}
