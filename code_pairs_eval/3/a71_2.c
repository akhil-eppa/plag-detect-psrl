 #include<stdio.h>
 int visit[10];
 int p[10];
 void creategraph();
 void path(int, int);
 int findpath(int,int); 
 int a[100][100],n;
 int length;
 main()
 {
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   creategraph();
   int i,v,s,d;
   printf("\nTo Find Path\n");
   printf("Enter the source and destination vertices..");
   scanf("%d %d",&s,&d);
   path(s,d);
  }
  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d %d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=1;
     }
  }
 int findpath(int s, int d)
 {
   visit[s]=1;
   int u;

   for(u=1;u<=n;u++)
   {
     if((a[s][u]==1)&&(visit[u]==0))
     {
        p[++length]=u;
        if((u==d)||findpath(u,d))
          return 1;
     }
  }
  --length;
 return 0;
}
 void path(int s, int d)
  {
   length=0;
   int i,j,t;

   p[length]=s;
   for(i=1;i<=n;i++)
      visit[i]=0;
  
   t=findpath(s,d);
   if(t)
   {
     printf("Path found..\n");
     printf("the length= %d",length);
     printf("the vertices in the path are..\n");
     for(j=0;j<=length;j++)
       printf("%d ",p[j]);
    }
    else
      printf("\nPath not found..\n");
 }