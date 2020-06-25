#include<stdio.h>
#include<stdlib.h>

int main(){
	
	long long int N ;
	// Number of test cases 
	//printf("N:") ;
	scanf(" %lld",&N) ;
	
	int arr[N][6] ;
	int count = 0 ;
	for(int i=0; i<N; ++i){
		for(int j=0; j<6; ++j){
			scanf(" %d",&arr[i][j]) ;
		}
	}
	
	int a,b,c ;
	
	for(int k=0;k<N;++k){
		a = (arr[k][0]-arr[k][2])*(arr[k][0]-arr[k][2]) + (arr[k][1]-arr[k][3])*(arr[k][1]-arr[k][3]) ;
		b = (arr[k][2]-arr[k][4])*(arr[k][2]-arr[k][4]) + (arr[k][3]-arr[k][5])*(arr[k][3]-arr[k][5]) ;
		c = (arr[k][0]-arr[k][4])*(arr[k][0]-arr[k][4]) + (arr[k][1]-arr[k][5])*(arr[k][1]-arr[k][5]) ;
		
		if(a+b==c || b+c==a || a+c==b){
			count++ ;
		}
	}
	
	printf("%d",count) ;
}