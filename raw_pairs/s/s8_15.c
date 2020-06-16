#include <stdio.h>
     
    #define N	100000
    #define MD	1000000007
     
    long long min(long long a, long long b) { return a < b ? a : b; }
     
    int main() {
    	int t;
     
    	scanf("%d", &t);
    	while (t-- > 0) {
    		static int aa[N];
    		static long long qq[N + 1];
    		int n, m, i, j, ans;
    		long long k, sum, p, x;
     
    		scanf("%d%d%lld", &n, &m, &k);
    		sum = 0;
    		for (i = 0; i < n; i++) {
    			scanf("%d", &aa[i]);
    			sum += aa[i];
    		}
    		qq[n] = 0;
    		for (i = n - 1; i >= 0; i--)
    			qq[i] = aa[i] + qq[i + 1];
    		ans = 0;
    		p = 0;
    		for (i = j = 0; j < n; j++) {
    			p += aa[j];
    			if (p <= k) {
    				x = min((k - p) / sum, m - 1);
    				if (x == m - 1)
    					ans = (ans + m * ((j + 1) * 2 + (long long) n * (m - 1)) / 2) % MD;
    				else {
    					int lower = 0, upper = n, h;
     
    					while (upper - lower > 1) {
    						h = (lower + upper) / 2;
    						if (qq[h] > (k - p) % sum)
    							lower = h;
    						else
    							upper = h;
    					}
    					ans = (ans + (long long) m * (j + 1)) % MD;
    					ans = (ans + n * x * (x + 1) / 2 + n * (m - 1 - x) * x) % MD;
    					ans = (ans + (m - 1 - x) * (n - upper)) % MD;
    				}
    			} else {
    				while (i <= j && qq[i] - qq[j + 1] > k)
    					i++;
    				ans = (ans + (long long) m * (j - i + 1)) % MD;
    			}
    		}
    		printf("%d\n", ans);
    	}
    	return 0;
    }