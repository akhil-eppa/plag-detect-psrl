 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void dfs(int);
 int n,a[100][100];
 int component();
 int label;
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
 int main()
 {
   int kix,i,vix; 
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph();
   int resulted =component();
   printf("the number of components = %d\n",resulted);
   printf ("\nthe vertices and their component numbers");
   for(i=1;n>=i;++i)
     printf("%d---> %d\n",i,visit[i]);
  }
    void dfs(int vix)
  {
    int u;
    visit[vix]=label;

    for(u=1;n>=u;++u)
    {
       if((visit[u]==0)&&(a[vix][u]==0))
           dfs(u);
    }
  }
  int component()
  {
   int j,i;
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