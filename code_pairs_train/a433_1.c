#include <stdio.h>
#include <string.h>
int main(void) {
int t;char m[101]; 
scanf("%d %s",&t,m);
while(t--){int n;
    scanf("%d",&n);
    char c[150]; scanf("%s",c);
    
  
    char c1[]="abcdefghijklmnopqrstuvwxyz";
    char c2[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;c[i]!='\0';i++){
        if(c[i]=='_'){printf(" "); }
         if(c[i]==','){printf(","); }
           if(c[i]=='!'){printf("!"); }
              if(c[i]=='.'){printf("."); }
                 if(c[i]=='?'){printf("?"); }
        for(int j=0;j<26;j++){if(c[i]==c1[j]){printf("%c",m[j]);}
        
        if(c[i]==c2[j]){printf("%c",toupper(m[j]));}
        
    }}
    
    
    printf("\n");
}
	return 0;
}

