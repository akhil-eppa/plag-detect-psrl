int main(void) {
int t,g,i,n,q,x;
scanf("%d",&t);
while(t--)
{
    scanf("%d",&g);
    for(x=0;x<g;x++)
    {
        scanf("%d %d %d",&i,&n,&q);
    if(i==1)
    {
        if(n%2==0)
        {
            printf("%d\n",n/2);  
        }
        else
        {
         if(q==1)
            printf("%d\n",n/2);
         else
            printf("%d\n",(n/2)+1);
            
        }  
    }
    else 
    {
        if(n%2==0)
        {
            printf("%d\n",n/2);  
        }
        else
         {
         if(q==1)
            printf("%d\n",(n/2)+1);
         else
            printf("%d\n",n/2);
            
        }     
    }
    }
}
return 0;
}