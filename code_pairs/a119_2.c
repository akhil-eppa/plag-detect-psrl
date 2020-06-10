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
int find(int belongs[],int vertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void kruskal();
void print();
void main()
{
	int i,j,t_cost;
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	kruskal();
	print();
}
void kruskal()
{
	int belongs[MAX],i,j,cn1,cn2;
	elist.n=0;
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(G[i][j]!=0)
			{
				elist.data[elist.n].u=i;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=G[i][j];
				elist.n++;
			}
		}
	sort();
	for(i=0;i<n;i++)
		belongs[i]=i;
	spanlist.n=0;
	for(i=0;i<elist.n;i++)
	{
		cn1=find(belongs,elist.data[i].u);
		cn2=find(belongs,elist.data[i].v);
		if(cn1!=cn2)
		{
			spanlist.data[spanlist.n]=elist.data[i];
			spanlist.n=spanlist.n+1;
			union1(belongs,cn1,cn2);
		}
	}
}
int find(int belongs[],int vertexno)
{
	return(belongs[vertexno]);
}
void union1(int belongs[],int c1,int c2)
{
	int i;
	
	for(i=0;i<n;i++)
		if(belongs[i]==c2)
			belongs[i]=c1;
}
void print()
{
	int i,cost=0;
	for(i=0;i<spanlist.n;i++)
	{
		printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
		cost=cost+spanlist.data[i].w;
	}
	printf("\n\nCost of the spanning tree=%d",cost);
}
void sort()
{
	int i,j;
	edge temp;
	for(i=1;i<elist.n;i++)
		for(j=0;j<elist.n-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}
}