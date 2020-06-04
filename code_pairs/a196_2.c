#include<stdio.h>
#define GU getchar_unlocked
#define fr(x,y) for(x=0;x<y;++x)
struct node{
	int aminb,aminc;
}array[1000005];
 
int cmp(const void* a,const void *b)
{
	struct node* f=(struct node*)a;
	struct node* g=(struct node*)b;
	if(f->aminb==g->aminb)
	return (f->aminc-g->aminc);
	else
	return (f->aminb-g->aminb);
}
 
 
int main()
{
	char x;
	int i=1,j,a=0,b=0,c=0,temp1=-1000000000,temp2=-1000000000;
	long long int ans=0,temp=0;
	array[0].aminb=array[0].aminc=0;
	while(1)
	{
		x=GU();
		if(x=='\n')break;
		else if(x=='A')
		a++;  
		else if (x=='B')
		b++;
		else 
		c++;
		array[i].aminb=a-b;
		array[i].aminc=a-c;
		i++;
		
	}
	qsort(array,i,sizeof(struct node),cmp);
	fr(j,i)
	{
		if(array[j].aminb!=temp1 || array[j].aminc!=temp2)
		{
			temp1=array[j].aminb;
			temp2=array[j].aminc;
			temp=0;
			
		}
		ans+=temp;
		temp++;
		
		
	}
	printf("%lld",ans);
	return 0;
 
} 