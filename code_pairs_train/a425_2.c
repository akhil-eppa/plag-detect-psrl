#include<stdio.h>
//#include<ctype.h>
int isupper(int ch)
{
	if(ch>=65 && ch<=90)
	return 1; // true 
	else 
	return 0;
}
int tolower(int ch)
{
	ch+=32;
	return ch;
}
int toupper(int ch)
{
	ch-=32;
	return ch;
}
int main()
{
	int t,n=0;//no of test cases
	char ch;     int flag=0;   // flag is 0 for lower case and 1 for upper case
	char arr[27];   
	scanf("%d",&t);
	
	getchar();  // this will take the space 
	for(n=0;n<26;n++)
	arr[n]=getchar();    
	getchar(); // this will take the enter
	
	n=0;
	while(n!=t)
	{		
		ch=getchar();   		
		
		while(ch!='\n')
		{
			if(isupper(ch)==1) //non zero means true 
			{   flag=1; ch=tolower(ch);  }
			
			if(ch>=95&&ch<=122&&ch!=96)
			{
				if(ch==95)
				printf(" ");
				else
				{
					if(flag==1) // upper case
					{
						ch=arr[ch-97];						
						printf("%c",toupper(ch));
					}
					else					
					printf("%c",arr[ch-97]);  					
				}
			   ch=getchar();
			}
			else
			{
				printf("%c",ch);
				ch=getchar();
			}
			//ch=getchar();  // instead of two getchars i made into one 
		   flag=0;	
		}
		
		printf("\n"); 
		n++;		
	}
return 0;
}