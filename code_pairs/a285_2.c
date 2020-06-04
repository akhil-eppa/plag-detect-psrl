#include <stdio.h>
#include <string.h>
main(){
	int T,tt;
	scanf("%d",&T);
	for(tt=0;tt<T;tt++){
		int i,j,count = 0;
		char J[100],S[100];
		scanf("%s%s",&J,&S);
		for(i=0;i<strlen(S);i++){
			for(j=0;j<strlen(J);j++){
				if(J[j]==S[i]){
					count++;
					break;
				}
			}
		}
		printf("%d\n",count);
	}
}