 //program to implement BFS for a digraph
 #include<stdio.h>
 int vst[100];
  int qdelete();
 int qisempty();
 void creategraph();
 void bfs(int);
 void qinsert(int);
 int a[100][100],n;
 int q[100];
 int f,r;
 int main()
 {
   int itt,v,k;
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
    int itt,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&itt,&j);
        if((itt==0)&&(j==0))
           break;
        a[itt][j]=1;
        a[j][itt]=1;
     }  
  }

  void bfs(int v)
  {
   int u,w;
   vst[v]=1;
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
       if((a[w][u]==1)&&(vst[u]==0))
       {
          vst[u]=1;
          printf("%d ",u);
          qinsert(u);
       }
     }
   }
 }
     
 void qinsert(int v)
  {
    r++;
    q[r]=v;
    if(f==-1)
      f=0;
  }
 int qisempty()
 {
   if(f==-1)
     return 1;
   return 0;
  }
 int qdelete()
 {
   int w;
   w=q[f];
   if(f==r)
     f=r=-1;
   else
      f++;
   return w;
  }