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
int find(int belong[],int vertexno);
void union1(int belong[],int c1,int c2);
void sort();
void print();
void main()
{
	int ind,j,total_cost;
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(ind=0;ind<n;ind++)
		for(j=0;j<n;j++)
			scanf("%d",&G[ind][j]);
	kruskal();
	print();
}
void kruskal()
{
	int belong[MAX],ind,j,cn1,cn2;
	elist.n=0;
	for(ind=1;ind<n;ind++)
		for(j=0;j<ind;j++)
		{
			if(G[ind][j]!=0)
			{
				elist.data[elist.n].u=ind;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=G[ind][j];
				elist.n++;
			}
		}
	sort();
	for(ind=0;ind<n;ind++)
		belong[ind]=ind;
	spanlist.n=0;
	for(ind=0;ind<elist.n;ind++)
	{
		cn1=find(belong,elist.data[ind].u);
		cn2=find(belong,elist.data[ind].v);
		if(cn1!=cn2)
		{
			spanlist.data[spanlist.n]=elist.data[ind];
			spanlist.n=spanlist.n+1;
			union1(belong,cn1,cn2);
		}
	}
}
int find(int belong[],int vertexno)
{
	return(belong[vertexno]);
}
void union1(int belong[],int c1,int c2)
{
	int ind;
	
	for(ind=0;ind<n;ind++)
		if(belong[ind]==c2)
			belong[ind]=c1;
}
void sort()
{
	int ind,j;
	edge temper;
	for(ind=1;ind<elist.n;ind++)
		for(j=0;j<elist.n-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temper=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temper;
			}
}
void print()
{
	int ind,cost=0;
	for(ind=0;ind<spanlist.n;ind++)
	{
		printf("\n%d\t%d\t%d",spanlist.data[ind].u,spanlist.data[ind].v,spanlist.data[ind].w);
		cost=cost+spanlist.data[ind].w;
	}
	printf("\n\nCost of the spanning tree=%d",cost);
}