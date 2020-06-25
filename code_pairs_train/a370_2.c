#include <stdio.h>

int findSum(int[], int, int, int);

int main(void) {
	// your code goes here
	int t,n,m,i,j,temp,result;
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d", &n, &m);
        
        if(n>20)
            return 0;
        
        int notes[n];
        for(i=0;i<n;i++){
            scanf("%d", &notes[i]);
            if(notes[i]>1000)
                return 0;
        }
        
        //arranging notes into increasing order of their values
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(notes[j]>notes[j+1]){
                    temp = notes[j];
                    notes[j]=notes[j+1];
                    notes[j+1]=temp;
                }
            }
        }
        
        //declaring result
        result = findSum(notes, 0, n-1, m);
        
        if(result)
            printf("Yes\n");
        else
            printf("No\n");
        
        }
    
        
        
    
	return 0;
}

int findSum(int arr[], int l, int r, int key){
    if(key==0)
        return 1;
        
    if(r-l+1 == 1){
        if(arr[l]==key)
            return 1;
        else    
            return 0;
    }
    
    return (findSum(arr,l,r-1,(key-arr[r]))||findSum(arr,l,r-1,key));
    
}