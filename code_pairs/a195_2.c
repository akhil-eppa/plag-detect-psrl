#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define lim 1000006
 
 
void merge(long arr[][2], long l, long m, long r)
{
    long i, j, k;
    long n1 = m - l + 1;
    long n2 =  r - m;
 
    long L[n1][2], R[n2][2];
 
    for (i = 0; i < n1; i++){
    	L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    
    for (j = 0; j < n2; j++){
    	R[j][0] = arr[m + 1+ j][0];
        R[j][1] = arr[m + 1+ j][1];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][1] <= R[j][1])
        {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}
 
void mergeSort(long arr[][2], long l, long r)
{
    if (l < r)
    {
        long m = l+(r-l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 
int main(void){
	char s[lim];
	long a_b[lim][2], a_c[lim], hash[2*lim];
	long i, j, n, a, b, c, m;
	long long p, ans;
	
	scanf("%s", s);
	n = strlen(s);
	
	a = b = c = 0;
	a_b[0][0] = 0;
	a_b[0][1] = 0;
	a_c[0] = 0;
	
	for(i = 0; i < n; i++){
		if(s[i] == 'A')
			a++;
		else if(s[i] == 'B')
			b++;
		else
			c++;
		
		a_b[i+1][0] = i+1;
		a_b[i+1][1] = a-b;
		a_c[i+1] = a-c;
	}
	
	mergeSort(a_b, 0, n);
	
 
	for(i = 0; i <= 2*n+2; i++)
		hash[i] = 0;

	i = 0;
	ans = 0;
	while(i < n){
		for(m = i; m < n; m++){
			if(a_b[m][1] == a_b[m+1][1])
				hash[n - a_c[a_b[m][0]]]++;
			else
				break;
		}
		hash[n - a_c[a_b[m][0]]]++;
		
		for(j = m; j >= i; j--){
			p = hash[n - a_c[a_b[j][0]]];
			hash[n - a_c[a_b[j][0]]] = 0;
			ans = ans + p*(p-1)/2;
		}
		
		i = m+1;
	}
	
	printf("%lld\n", ans);
				
	return 0;
} 