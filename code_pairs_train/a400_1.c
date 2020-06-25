//
//  main.c
//  practica16
//  Iñaki Janeiro Olague A00516978

#include <stdio.h>

int main() {
    
    int t, n;
    
    scanf("%d", &t);
        
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int rootID = 0;
        for (int j = 0; j < n; j++) {
            int id, sum;
            
            scanf("%d", &id);
            scanf("%d", &sum);
            
            rootID += id;
            rootID -= sum;
        }
        printf("%d\n", rootID);
    }
    
    
    
    return 0;
}
