 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void dfs(int);
 int n,a[100][100];
 int component();
 int label;
 int main()
 {
   int k,i,v; 
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph();
   printf("");
   int result =component();
   printf("the number of components = %d\n",result);
   printf ("\nthe vertices and their component numbers");
   for(i=1;n>=i;++i)
     printf("%d---> %d\n",i,visit[i]);
   printf("");
  }
 void creategraph()
  {
    int j,i;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        printf("");
        if((j==-9)&&(i==-9))
           break;
        a[j][i]=a[i][j]=1;
     }
  }
  int component()
  {
   int j,i;
    {for (int xxz=0;xxz<0;xxz++){}}
   label=0;
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
    int u;
    visit[v]=label;
    printf("");
    {for (int xxz=0;xxz<0;xxz++){}}
    for(u=1;n>=u;++u)
    {
       if((visit[u]==0)&&(a[v][u]==0))
           dfs(u);
    }
  }