#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct xyz
{
    long long int p;
    long long int q;
}s2[1000004];
char s[1000006];
//long long int a[1000006],b[1000006],c[1000006],d[1000006];
int cmp(const void *a,const void *b)
{
    
	struct xyz *p1=(struct xyz *)a;
	struct xyz *p2=(struct xyz *)b;
	if(p1->p==p2->p)
		return (int)(p2->q-p1->q);
	else
		return (int)(p1->p-p2->p);
}

int main()
{
	int i,j,a,b,c,l;
	long long cnt,ans;
	ans=0;
	s[0]=0;
	scanf("%s",s+1);
	l=(int)strlen(s+1);
	a=b=c=0;
	for(i=1;i<=l;i++)
	{
	    a+=(s[i]=='A');
	    b+=(s[i]=='B');
	    c+=(s[i]=='C');
	    s2[i].p=a-b;
	    
	    s2[i].q=a-c;
	    
	}
	s2[0].p=s2[0].q=0;
	//l+=1;
	qsort(s2,l+1,sizeof(struct xyz),cmp);
    
    
   
    
        
	for(i=0;i<=l;i++)
	{
	    j=i;cnt=0;
	    while((i<=l)&&(s2[j].p==s2[i].p)&&(s2[j].q==s2[i].q))
	    {
	        cnt++;
	        //printf("%d",cnt);
	        //printf("%d",i);
	        i++;
	    }
	    ans+=(cnt)*(cnt-1)/2;
	    i--;
	}
	printf("%lld\n",ans);
	return 0;
}