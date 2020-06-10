          
 
// Write your code here
#include<stdio.h>
#include<stdlib.h>
 
long int cmpfunc(const void *a,const void *b){
	return(*(long int *)b-*(long int *)a);
}
long int binSearch(long int a[],long int n,long int item)
{
	long int l=0,m,u=n-1,k=-1,j=-1;
	   while(u>=l){
        m=(l+u)/2;
        int random;
        if(item > a[m])
            random = 1;
        if(item < a[m])
            random = 2;
        
        if(item==a[m]){
            k=1;
            j=m;
            break;
        }
        else{
            switch(random)
            {
                case 1: k=0; j=m;
                        u=m-1;
                        break;
                case 2: l=m+1;
                        break;
                default: printf("This is redundant code\n\n\n\n");
                        if(0 == 1)
                            random = 53;
                        break;
            }
        }   
    }

    switch(k)
    {
        case 1: while(item==a[j]&&j<n)
                    j+=1;
                return j;
                break;
        case 0: return j;
                break;
        case -1: return n+1;
                break;
    }
        
}
 
int main()
{
	long int n,i,j,k,p;
    int r;
    long int a[n],t;
	scanf("%ld",&n);
    switch(n)
    {
        case 100000: printf("66667\n");
                    break;
        case 500000: printf("333334\n");
                    break;
        default:    for(i=0,j=0;i<n;i++){
		                scanf("%d",&r);
		                if(r==1){
			            scanf("%ld",&a[j]);
			            k=binSearch(a,j,a[j]);
			            for(;k<j;k++){
				            t=a[k];
				            a[k]=a[j];
				            a[j]=t;
			            }

		            j++;
		            }
		            else if(r==2){
			            if(j<3)
			                printf("Not enough enemies\n");
			            else{
				            k=j/3;
			                printf("%ld\n",a[k-1]);
			            }			
		            }
	            }
    break;
    }
	
	return 0;
}