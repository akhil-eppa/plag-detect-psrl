 //program to implement BFS for a digraph
 //graph is created using the creategraph() function
 //many helper functions have been created
 #include<stdio.h>
 int visit[100];
 void creategraph();//create a graph based on the inputs
 void bfs(int);//breadth first search
 void qinsert(int);//insert into the search portion
 int qdelete();//delete 
 int qisempty();//check if empty. if empty take suitable actions
 int a[100][100],n;//graph
 int q[100];
 int f,r;
 int main()
 {
   int i,v,k;
   printf("Enter the number of vertices..");//accepts number of vertices
   scanf("%d",&n);//accepts integer n
   creategraph();
   printf("Enter the source vertex..\n");
   scanf("%d",&v);//accepting v

   printf("The vertices reachable from %d using BFS are..\n",v);
   bfs(v);//calling the bfs functin
 
  }

  void creategraph()//creates a graph. accept which is connected to what
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);//accepting
        if((i==0)&&(j==0))
           break;
        a[i][j]=1;
        a[j][i]=1;
     }  
  }

  void bfs(int v)
  {
   int u,w;
   visit[v]=1;
   printf("%d ",v);
   qinsert(v);//insert into the queue

   while(!qisempty())
   {
     w=qdelete();
     //if queue is not empty, delete from the queue
     for(u=1;u<=n;u++)//loop to check all its connections
     {
       if((a[w][u]==1)&&(visit[u]==0))
       {
          visit[u]=1;
          printf("%d ",u);
          qinsert(u);//insert the connection into the queue
       }
     }
   }
 }
     
 void qinsert(int v)//insert into the queue
  {
    r++;
    q[r]=v;
    if(f==-1)
      f=0;
  }


 int qdelete()//delete from the queue
 {
   int w;
   w=q[f];
   if(f==r)
     f=r=-1;
   else
      f++;
   return w;
  }

 int qisempty()//check if queue is empty
 {
   if(f==-1)
     return 1;
   return 0;
  }