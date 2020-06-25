#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int gcd(int a, int b){
    if(a<b)
        return gcd(b, a);
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int T, A;
    char str[260];
    scanf("%d", &T);
    for(int i=0; i<T; ++i){
        scanf("%d ", &A);
        scanf("%s", str);
        if(A==0)
            printf("%s\n", str);
        else{
        int rem=0, prod=1;
        for(int j=strlen(str)-1; j>=0; --j){
            rem=(rem+ prod*(str[j]-'0'))%A;
            prod=(prod*10)%A;
        }
        printf("%d\n", gcd(A, rem));
        }
    }
    return 0;
}