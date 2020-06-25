#include <stdio.h>
#include<string.h>

int main(void) {
	// your code goes here
	int n,i,j,k,t,o;
	scanf("%d\n",&t);
	
	for(o=0;o<t;o++){
	    char s[100],j[100];
	    gets(j);
	    gets(s);
	    
	    int J=strlen(j);
	    int S=strlen(s);
	    
	    int sum=0;
	    for(i=0;i<S;i++){
	        for(k=0;k<J;k++){
	            if(s[i]==j[k]){
	                sum+=1;
	                break;
	            }
	        }
	    }
	    printf("%d\n",sum);
	}
	return 0;
}