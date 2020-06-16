#include<stdio.h>
#include<stdlib.h>

int a[100][100];
int visit[10];
void dfs(int v, int n);
void creategraph();
int main()
{
	int n,v;
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	creategraph();
	printf("enter the src vertex\n");
	scanf("%d",&v);
	printf("vertex reachable from %d using DFS are..\n", v);
	dfs(v,n);
}

void creategraph()
{
	int i,j;
	while(1)
	{
		printf("enter the src and destination.....");
		scanf("%d%d",&i,&j);
		if((i==0)||(j==0)) break;
		a[i][j]=a[j][i]=1;//undirected graph
	}
}


void dfs(int v, int n)
{
	int w;
	visit[v]=1;
	printf("%d",v);
	for(w=1;w<=n;w++)
		{
			if((a[v][w]==1) && (visit[w]==0))
			dfs(w,n);
		}
}





















