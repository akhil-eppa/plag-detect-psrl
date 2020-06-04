 #include<stdio.h>
 int visit[10];//visit array
 int p[10];
 void creategraph();//creates a graph
 void path(int, int);
 int findpath(int,int); //finds the path
 int a[100][100],n;//array to store the graph
 int length;
 main()
 {
   /*
   All the helper functions are called from here
   This is the heart of the program
   */  
   int i,v,s,d;
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   /*
   Create a graph based on accepted inputs
   */
   creategraph();
   printf("\nTo Find Path\n");//fnding path
   printf("Enter the source and destination vertices..");
   scanf("%d %d",&s,&d);
   path(s,d);//path from source to destination
  }
  /*
  The function below creates a graph.
  We accept input as to what nodes are connected.
  Based on that we create the graph
  */
  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d %d",&i,&j);
        if((i==-9)&&(j==-9))//end
           break;
        a[i][j]=1;
     }
  }
 int findpath(int s, int d)//function to find the path
 {
   int u;
   visit[s]=1;
   //path is stored in the p array
   //a is the graph
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
 /*
 This is the path function
 It calls the findpath function
 If the path is found, it prints
 the path as required
 */
 void path(int s, int d)
  {
   int i,j,t;
   length=0;

   for(i=1;i<=n;i++)
      visit[i]=0;

   p[length]=s;
  
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