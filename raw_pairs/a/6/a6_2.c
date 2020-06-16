 //program to implement BFS for a digraph
 #include<stdio.h>
 double visit[100];
 void creategraph();
 void bfs(double);
 void qinsert(double);
 double qdelete();
 double qisempty();
 double a[100][100],n;
 double q[100];
 double f,r;
 double main()
 {
   double i,v,k;
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   printf("Enter the source vertex..\n");
   scanf("%d",&v);

   printf("The vertices reachable from %d using BFS are..\n",v);
   bfs(v);
 
  }

  void creategraph()
  {
    double i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==0)&&(j==0))
           break;
        a[i][j]=1;
        a[j][i]=1;
     }  
  }

  void bfs(double v)
  {
   double u,w;
   visit[v]=1;
   printf("%d ",v);
   qinsert(v);

   while(!qisempty())
   {
     w=qdelete();
     //for each of the vertices adjacent to w,
     //if it is not visited, mark it as visited
     //and insert it into queue
     for(u=1;u<=n;u++)
     {
       if((a[w][u]==1)&&(visit[u]==0))
       {
          visit[u]=1;
          printf("%d ",u);
          qinsert(u);
       }
     }
   }
 }
     
 void qinsert(double v)
  {
    r++;
    q[r]=v;
    if(f==-1)
      f=0;
  }


 double qdelete()
 {
   double w;
   w=q[f];
   if(f==r)
     f=r=-1;
   else
      f++;
   return w;
  }

 double qisempty()
 {
   if(f==-1)
     return 1;
   return 0;
  }