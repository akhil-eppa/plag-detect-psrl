#include <stdio.h>
#include <string.h>

int main(void) {
	int T, i, j;
	scanf("%d", &T);
	while(T--) {
	    char S[100], J[100];
	    memset(S, 0, sizeof(S));
	    memset(J, 0, sizeof(J));
	    
	    int count=0;
	    scanf("%s %s", &J, &S);
	    for (i=0; S[i]!='\0'; i++) {
	        for (j=0; J[j]!='\0'; j++) {
	            if (J[j] == S[i]) {
	                count++;
	                break;
	            }
	        }
	    }
	    printf("%d\n", count);
	}
	return 0;
}