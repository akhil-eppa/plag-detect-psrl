#include <stdio.h>
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int c = 100;
        char s1[100];
        while(n--){
            char s[100];
            scanf("%s",s);
            int v[26] = {0};
            for(int i = 0; i < strlen(s); i++){
                v[s[i] - 97]++;
            }
            int count = 0;
            for(int i = 0; i < 26; i++){
                if(v[i]  > 0){
                    count++;
                }
            }
            if(c >= count){
                strcpy(s1,s);
                c = count;
            }
        }
        printf("%s\n",s1);
    }
    return 0;
}