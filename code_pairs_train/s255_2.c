#include <stdio.h>
#include <string.h>
 
#define N 100000
 
long long SortAndCount(int* arr, int len){
    long long pairCount = 0;
    if(len > 1){
        int val = arr[0];
        long long count = 1;
        for(int i = 1; i < len; i++){
            if(arr[i]==val){
                count++;
            }
            else{
                arr[i-count] = arr[i];
            }
        }
        pairCount = (count*(count-1))/2 + SortAndCount(arr, len - count);
    }
    return pairCount;
}
long long  CountBalanced(void){
    int array[N];
    long long count = 0;
    int len = 1;
    int chr = getchar();
    while((chr != '\n') && (chr != EOF)){
        array[len] = (array[len-1])^(1<<(chr-'a'));
        len++;
        chr = getchar();
    }
    return SortAndCount(array, len);
}
 
int main(){
    int testCases = 0;
    scanf("%d", &testCases);
    getchar();
    while(testCases--){
        long long balancedCount = CountBalanced();
    	printf("%lld\n", balancedCount);
    }
    return 0;
}