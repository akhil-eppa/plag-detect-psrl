#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int sum);

int main(void)
{
	int t;
	int n, m;
	int bnk[20];
	int i;
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) scanf("%d", &bnk[i]);
		if (isSubsetSum(bnk, n, m) == true) 
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

// Returns true if there is a subset of set[] with sun equal to given sum 
bool isSubsetSum(int set[], int n, int sum) 
{ 
   // Base Cases 
   if (sum == 0) 
     return true; 
   if (n == 0 && sum != 0) 
     return false; 
  
   // If last element is greater than sum, then ignore it 
   if (set[n-1] > sum) 
     return isSubsetSum(set, n-1, sum); 
  
   /* else, check if sum can be obtained by any of the following 
      (a) including the last element 
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) ||  
                        isSubsetSum(set, n-1, sum-set[n-1]); 
} 
