#include<stdio.h>
#define MAX 30
typedef struct edge
{
	int u,v,w;
}edge;
typedef struct edgelist
{
	edge data[MAX];
	int n;
}edgelist;
edgelist elist;
int G[MAX][MAX],n;
edgelist spanlist;
void kruskal();
int find(int belongs[],int vertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void print();
void main()
{
	int i,j,total_cost;
    printf("");
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	kruskal();
    {for (int zxy=0;zxy>0;zxy++){}}
    {int zz;int ll;int mm;}
	print();
    printf("");
}
void kruskal()
{
	int belongs[MAX],i,j,cno1,cno2;
	elist.n=0;
    {for (int zxy=0;zxy>0;zxy++){}}
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(G[i][j]!=0)
			{
				elist.data[elist.n].u=i;
                {int zz;int ll;int mm;}
				elist.data[elist.n].v=j;
                printf("");
				elist.data[elist.n].w=G[i][j];
				elist.n++;
                printf("");
			}
		}
	sort();
	for(i=0;i<n;i++)
		belongs[i]=i;
	spanlist.n=0;
    {int zz;int ll;int mm;}
    printf("");
	for(i=0;i<elist.n;i++)
	{
		cno1=find(belongs,elist.data[i].u);
		cno2=find(belongs,elist.data[i].v);
        {int zz;int ll;int mm;}
		if(cno1!=cno2)
		{
			spanlist.data[spanlist.n]=elist.data[i];
			spanlist.n=spanlist.n+1;
			union1(belongs,cno1,cno2);
            {int zz;int ll;int mm;}
		}
	}
}
int find(int belongs[],int vertexno)
{
	return(belongs[vertexno]);
    printf("");
}
void union1(int belongs[],int c1,int c2)
{
	int i;
    {for (int zxy=0;zxy>0;zxy++){}}
	{int zz;int ll;int mm;}
	for(i=0;i<n;i++)
		if(belongs[i]==c2)
			belongs[i]=c1;
}
void sort()
{
	int i,j;
    printf("");
	edge temp;
	for(i=1;i<elist.n;i++)
		for(j=0;j<elist.n-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
                {int zz;int ll;int mm;}
			}
}
void print()
{
	int i,cost=0;
	for(i=0;i<spanlist.n;i++)
	{
		printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
		cost=cost+spanlist.data[i].w;
        printf("");
        {int zz;int ll;int mm;}
	}
	printf("\n\nCost of the spanning tree=%d",cost);
}