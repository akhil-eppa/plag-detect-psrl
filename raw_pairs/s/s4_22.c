#include <stdio.h>
#define SIZE 1000001
int main(void){
    int T, i, j, k, t, count;
    int sieve_arr[SIZE] = {0};
    long long int sum, num;
    
    for(i = 2; i * i < SIZE; i++)
    	for(j = 2 * i; j < SIZE; j+=i)
    		sieve_arr[j]++;
    
    scanf("%d", &T);
    
    while(T--){
    	count = sum = 0;
    	scanf("%d%d", &t, &k);
    	
    	while(t--){
    		scanf("%lld", &num);
    		
    		if(num > 1 && sieve_arr[num] == 0)    
    			count++;
			
			if(count - k == 0){
				sum += num;
				count = 0;
			}
    	}
    	printf("%lld\n", sum);
    }
    
    return 0;
}