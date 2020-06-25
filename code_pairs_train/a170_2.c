 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int visit[100];
 int component();
 int label;
 void creategraph();
 void dfs(int);
 int n,a[100][100];
 int main()
 {
   int k,i,v; 
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph();
   int result =component();
   printf("the number of components = %d\n",result);
   printf ("\nthe vertices and their component numbers");
   for(i=1;i<=n;i++)
     printf("%d---> %d\n",i,visit[i]);
  }
 void creategraph()
  {
    int j,i;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=a[j][i]=1;
     }
  }
  int component()
  {
   int i,j;
   label=0;
   for(i=1;i<=n;i++)
   {
     if(visit[i]==0)
     {
       ++label;
       dfs(i);
     }
  }
  return label;
 }
  void dfs(int v)
  {
    int u;
    visit[v]=label;

    for(u=1;u<=n;u++)
    {
       if((a[v][u]==0)&&(visit[u]==0))
           dfs(u);
    }
  }