#include <stdio.h>

int main(void) {
	// your code goes here
	
	int n;
	scanf("%d",&n);
	
	char s[27],a[101];
	scanf("%s",s);
	
	int i,j;
	
	for(i=0;i<n;i++)
	{
	    scanf("%s",a);
	    
	    for(j=0;a[j]!='\0';j++)
	    {
	        if(a[j]=='_')
	        printf(" ");
	        
	        if(a[j]==','||a[j]=='?'||a[j]=='!'||a[j]=='.')
	        printf("%c",a[j]);
	        
	        if(a[j]>='a'&&a[j]<='z'||a[j]>='A'&&a[j]<='Z')
	        {
	            if(a[j]>='A'&&a[j]<='Z')
	            printf("%c",toupper(s[a[j]-'A']));
	            
	            else
	            printf("%c",s[a[j]-'a']);
	        }
	    }
	    printf("\n");
	    
	}

	
	return 0;
}

