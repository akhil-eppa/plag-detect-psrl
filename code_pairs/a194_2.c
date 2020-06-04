#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<algorithm>
int a[1000006]={0},b[1000006]={0},c[1000006]={0};
char arr[1000006];
struct node
{
    long long int p;
    long long int q;
}s[1000006];
int compare(const void*a,const void*b)
{
	struct node* x=(struct node*)a;
	struct node* y=(struct node*)b;
	if(x->p==y->p)		return (x->q-y->q);
	else		return(x->p-y->p);
}
int main()
{
    int i=0,len;
    scanf("%s",arr);
    len=strlen(arr);
    long long int cnt=0,temp=0;//p[0]=make_pair(0,0);
    for(i=1;i<=len;i++)
    {
            if(arr[i-1]=='A')
            {
                 a[i]=a[i-1]+1;
                 b[i]=b[i-1];
                 c[i]=c[i-1];
                 }
            else if(arr[i-1]=='B')
            {
                 a[i]=a[i-1];
                 b[i]=b[i-1]+1;
                 c[i]=c[i-1];
                 }
            else if(arr[i-1]=='C')
            {
                 a[i]=a[i-1];
                 b[i]=b[i-1];
                 c[i]=c[i-1]+1;
                 }
            s[i].p=(b[i]-a[i]);
            s[i].q=(c[i]-a[i]);
            }
    s[0].p=0;s[0].q=0;
    qsort(s,len+1,sizeof(struct node),compare);
    struct node test;
    test.p=-100000000;test.q=-100000000;
    /*
    for(int i=0;i<=strlen(arr);i++)		printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<=strlen(arr);i++)		printf("%d ",b[i]);
    printf("\n");
    for(int i=0;i<=strlen(arr);i++)		printf("%d ",c[i]);
    printf("\n");*/
    for(i=0;i<=len;i++)
    {
            if(!(s[i].p==test.p && s[i].q==test.q))
            {
                  test.p=s[i].p;test.q=s[i].q;
                  temp=0;
                  }
            cnt+=temp;
            temp+=1;
            }
    printf("%lld\n",cnt);
    //system("pause");
    return 0;
    }  