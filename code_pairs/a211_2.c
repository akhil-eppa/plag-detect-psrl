#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    while(t>0){
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        } 
        int k,temp=0;
        scanf("%d",&k);
        int c=a[k-1];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]){
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        } 
        for(int i=0;i<n;i++){
            if(a[i]==c){
                printf("%d\n",i+1);
                break;
            }
        } 
        t--;
    }
	return 0;
}

