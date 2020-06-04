#include <stdio.h>
int main() {
    int T,found;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int X, Y, K, N;
        scanf("%d%d%d%d", &X, &Y, &K, &N);
         found = 0;
        for (int i = 0; i < N; i++) {
            int P, C;
            scanf("%d%d", &P, &C);
            if (P >= X - Y && C <= K) {
                found = 1;
            }
        }
        printf(found ? "LuckyChef\n" : "UnluckyChef\n");
    }
}