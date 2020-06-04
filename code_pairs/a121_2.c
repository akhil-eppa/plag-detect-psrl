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
void kruskal();//function for kruskal algorithm
int find(int belongs[],int vertexno);//finding if it belongs
void union1(int belongs[],int c1,int c2);//finding the union that would constitute the final set
void sort();
void print();
void main()
{
	int i,j,total_cost;//total cost is stored up here
	printf("\nEnter number of vertices:");//number of vertices to be accepted
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");//adjacency matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);//acceptance
	kruskal();
	print();
}
void kruskal()//this is the kruskal algorithm that is used
{
	int belongs[MAX],i,j,cno1,cno2;//multiple variables
	elist.n=0;
	for(i=1;i<n;i++)//nested for loop that would be used
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
	sort();//sorting in increasing order of weights
	for(i=0;i<n;i++)
		belongs[i]=i;
	spanlist.n=0;
	for(i=0;i<elist.n;i++)
	{
		cno1=find(belongs,elist.data[i].u);//checking the belonging
		cno2=find(belongs,elist.data[i].v);//checking the belonging
		if(cno1!=cno2)//check
		{
			spanlist.data[spanlist.n]=elist.data[i];
			spanlist.n=spanlist.n+1;
			union1(belongs,cno1,cno2);//creating a union by calling the union function
		}
	}
}
int find(int belongs[],int vertexno)//finding if a given vertex belongs to a set, useful
{
	return(belongs[vertexno]);
}
void union1(int belongs[],int c1,int c2)//getting a union
{
	int i;
	
	for(i=0;i<n;i++)
		if(belongs[i]==c2)
			belongs[i]=c1;
}
void sort()//sorting the edges based on the weight, this is how its done
{
	int i,j;
	edge temp;
	for(i=1;i<elist.n;i++)//again another nested loop
		for(j=0;j<elist.n-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}
}
void print()//printing the obtained minimum spanning tree
{
	int i,cost=0;
	for(i=0;i<spanlist.n;i++)//printing
	{
		printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
		cost=cost+spanlist.data[i].w;
	}
	printf("\n\nCost of the spanning tree=%d",cost);
}