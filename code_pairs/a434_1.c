#include <stdio.h>
#include <string.h>

int main() {

	int t;
	scanf("%d", &t);
     char trans[30];
     scanf("%s", trans);

	while (t--) {
          
          int len;
          char a[200];
          scanf ("%s", a);
          len = strlen(a);
          
          for (int i = 0; i < len; i++) {
               
               if (a[i] >= 97 && a[i] <= 122) {
                    int temp = a[i] - 97;
                    printf("%c", trans[temp]);
               }
               else if (a[i] >= 65 && a[i] <= 90) {
                    int temp = a[i] - 65;
                    printf("%c", trans[temp] - 32);
               }
               else if (a[i] == '_') {
                    printf(" ");
               }
               else {
                    printf("%c", a[i]);
               }
          
          }
          
          printf("\n");
          
	}
}