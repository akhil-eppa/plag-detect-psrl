 #include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<math.h>
 
char* solve (int N ) {
   // Your code goes her
   int limit = sqrt(N);
   char* res = "No";
   if(N == 2)
    {
        res = "No";
    }
    else
    {
        for(int i=2;i <= limit; i++)
        {
        if(N%i == 0)
        {
            res = "Yes";
            break;
        }
        }
    }
    return res;
}
 
int main() {
    int T;
    scanf("%d", &T);
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        scanf("%d", &N);
 
        char* out_ = solve(N);
        printf("%s", out_);
        printf("\n");
    }
}