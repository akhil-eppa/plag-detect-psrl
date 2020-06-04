#include<stdio.h>
int Gcd(int ,int );
void main()
{
   int gcd,i,a,b,num,rem,n;
   char array[300];
   scanf("%d",&n);
   while(n--)
   {
   scanf("%d",&a);
   scanf("%s",array);
   rem=0;
   if(a==0)
   printf("%s\n",array);
   else
   {
   for(i=0;array[i]!='\0';i++)
   {
   num=rem*10+(array[i]-'0');
   rem=num%a;
   }
   b=rem;
   gcd=Gcd(a,b);
   printf("%d\n",gcd);
   }
 }
}
   int Gcd(int a, int b)
   {
   if(b==0)
   return a;
   else
   return Gcd(b,a%b);
} 