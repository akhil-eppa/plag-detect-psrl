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
   int i,v,s,d;
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   printf("\nTo Find Path\n");
   printf("Enter the source and destination vertices..");
   scanf("%d %d",&s,&d);
   path(s,d);
  }
  void creategraph()
  {
    int i,j;
    for (int i=1;i>0;i++)
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
   int u=1;
   visit[s]=1;

   while (u<=n)
   {
     if((a[s][u]==1)&&(visit[u]==0))
     {
        p[++length]=u;
        if((u==d)||findpath(u,d))
          return 1;
     }
     u++;
  }
  --length;
 return 0;
}
 void path(int s, int d)
  {
   int i,j,t;
   length=0;
   i=1;
   while (i<=n)
   {
      visit[i]=0;
      i++;
   }

   p[length]=s;
  
   t=findpath(s,d);
   if(t)
   {
     printf("Path found..\n");
     printf("the length= %d",length);
     printf("the vertices in the path are..\n");
     j=0;
     while (j<=length)
     {
       printf("%d ",p[j]);
       j++;
     }
    }
    else
      printf("\nPath not found..\n");
 }