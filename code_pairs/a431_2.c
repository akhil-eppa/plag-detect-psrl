# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(){
	int t;
	char M[26];

	scanf("%d", &t);
	scanf("%s", M);
	
	while(t--){
		char input[100];

		scanf("%s", &input);
		for(int i=0; i<strlen(input); i++){
			if(input[i]>=65 && input[i]<=90){
				printf("%c", toupper(M[input[i]-65]));
				continue;
			}else if(input[i]>=97 && input[i]<=122){
				printf("%c", (M[input[i]-97]));
				continue;
			}else if(input[i] == '_'){
				printf(" ");
				continue;
			}else{
				printf("%c", input[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
