 //program to return the no of components of disconnected graph
 #include<stdio.h>
  void dfs(int);
 int n,a[100][100];
 int component();
 int visit[100];
 void creategraph();
 int label;
 int main()
 {
   int k,i,v; 
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph();
   int result =component();
   printf("the number of components = %d\n",result);
   printf ("\nthe vertices and their component numbers");
   for(i=1;n>=i;++i)
     printf("%d---> %d\n",i,visit[i]);
  }
 void creategraph()
  {
    int j,i;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((j==-9)&&(i==-9))
           break;
        a[j][i]=a[i][j]=1;
     }
  }
  int component()
  {
   label=0;
   int j,i;
   for(i=1;n>=i;++i)
   {
     if(visit[i]==0)
     {
       label++;
       dfs(i);
     }
  }
  return label;
 }
  void dfs(int v)
  {
     visit[v]=label;
    int u;
    for(u=1;n>=u;++u)
    {
       if((visit[u]==0)&&(a[v][u]==0))
           dfs(u);
    }
  }