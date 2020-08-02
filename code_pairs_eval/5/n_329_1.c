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
		if( r > tx )
			r = tx;
		// ( z - r, z - l )
		if( z - l > ty )
			l = z - ty;
		ways[z] = max(0, r - l + 1);
		if( z > 0 )
			ways[z] += ways[z-1];
	}
	for( int z = max(0,lz); z<=rz; ++z ) {
		ans += ways[z];
	}
	printf("%lld\n", (((1ll*(b-a+1))*(c-b+1))*(d-c+1)) - ans);
}
