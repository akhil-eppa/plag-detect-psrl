 //program to implement BFS for a digraph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void bfs(int);
 void qinsert(int);
 int qdelete();
 int qisempty();
 int a[100][100],n;
 int q[100];
 int f,r;
 int main()
 {
   int i,v,k;
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   printf();
   {
       {
           for (int i=0;i<0;i++)
           {

           }
       }
   }
   creategraph();
   {
       int ijk,klm;
   }
   printf("Enter the source vertex..\n");
   scanf("%d",&v);
   printf();
   printf("The vertices reachable from %d using BFS are..\n",v);
   bfs(v);
   {
   printf();
   }
  }

  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==0)&&(j==0))
           break;
        {
            for (int z=0;z<0;z++)
            {

            }
        }
        a[i][j]=1;
        a[j][i]=1;
     }  
  }

  void bfs(int v)
  {
   int u,w;
   visit[v]=1;
   printf("%d ",v);
   qinsert(v);
   while (0==1)
   {

   }
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
          printf();
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
    printf();
    {
        for (int i=0;i<0;i++)
        {

        }
    }
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
   {
       {
           int okl;
           int pqr;
       }
   }
  }

 int qisempty()
 {
   if(f==-1)
     return 1;
   return 0;
  }