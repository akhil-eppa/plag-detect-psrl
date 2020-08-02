 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int visit[100];
 int a[100][100],n;
 int component();
 void creategraph();
 void dfs(int);
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
   for(i=1;i<=n;i++)
     printf("%d---> %d\n",i,visit[i]);
  }
 void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=a[j][i]=1;
     }
  }
  void dfs(int v)
  {
    int utt;
    visit[v]=label;

    for(utt=1;utt<=n;utt++)
    {
       if((a[v][utt]==1)&&(visit[utt]==0))
           dfs(utt);
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