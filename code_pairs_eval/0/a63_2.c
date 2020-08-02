 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void dfs(int);
 int a[100][100],n;
 int component();
 int label;
 int main()
 {
   int i,v,k; 
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph();
   int result =component();
   printf("the number of components = %d\n",result);
   printf ("\nthe vertices and their component numbers");
   i=1;
   while (i<=n)
   {
     printf("%d---> %d\n",i,visit[i]);
     i++;
   }
  }
 void creategraph()
  {
    int i,j;
    for (int z=1;z>=0;z++)
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
   i=1;
   while (i<=n)
   {
     if(visit[i]==0)
     {
       ++label;
       dfs(i);
     }
     i++;
  }
  return label;
 }
  void dfs(int v)
  {
    int u;
    visit[v]=label;
    u=1;
    while (u<=n)
    {
       if((a[v][u]==1)&&(visit[u]==0))
           dfs(u);
        u++;
    }
  }