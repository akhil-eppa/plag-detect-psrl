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
int get_count(int arr[], int len, int k){
	int count=0;
	for(int i=0;i<len;i++){
		
		int sum=0;
		for(int j=i;j<len;j++){
			if(sum+arr[j]<=k){
				sum=sum+arr[j];
				count++;
			}
			else{
				break;
			}
					
		}
		
	}
	return count;
}
 
int main(){
	int t;
	scanf("%d", &t);
	while(t-->0){
		int n, m, k;
		scanf("%d%d%d", &n,&m,&k);
		int a[n];
		int b[n*m];
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
			for(int j=0;j<m;j++){
				b[(n*j+i)%(n*m)]=a[i];
			}
		}
		int len=n*m;
		int count=0;
		count= get_count(b, len, k);
		printf("%d\n", count);
	}
	return 0;
}
