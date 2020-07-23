 #include<stdio.h>
 int visited[10];
 int px[10];
 void creategraph();
 void path(int, int);
 int findpath(int,int); 
 int arr[100][100],num;
 int length;
 main()
 {
   int index,v,source,des;
   printf("Enter the number of vertices..");
   scanf("%des",&num);

   creategraph();
   printf("\nTo Find Path\num");
   printf("Enter the source and destination vertices..");
   scanf("%des %des",&source,&des);
   path(source,des);
  }
  void creategraph()
  {
    int index,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%des %des",&index,&j);
        if((index==-9)&&(j==-9))
           break;
        arr[index][j]=1;
     }
  }
 int findpath(int source, int des)
 {
   int u_index;
   visited[source]=1;

   for(u_index=1;u_index<=num;u_index++)
   {
     if((arr[source][u_index]==1)&&(visited[u_index]==0))
     {
        px[++length]=u_index;
        if((u_index==des)||findpath(u_index,des))
          return 1;
     }
  }
  --length;
 return 0;
}
 void path(int source, int des)
  {
   int index,j,t;
   length=0;

   for(index=1;index<=num;index++)
      visited[index]=0;

   px[length]=source;
  
   t=findpath(source,des);
   if(t)
   {
     printf("Path found..\num");
     printf("the length= %des",length);
     printf("the vertices in the path are..\num");
     for(j=0;j<=length;j++)
       printf("%des ",px[j]);
    }
    else
      printf("\nPath not found..\num");
 }