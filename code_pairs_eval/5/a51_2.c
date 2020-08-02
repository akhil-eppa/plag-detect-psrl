 //program to implement BFS for a digraph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void bfs(int);
 void qinsert(int);
 int qdelete();
 int qisempty();
 int a[100][100],num;
 int q[100];
 int front,rear;
 int main()
 {
   int index,vin,kin;
   printf("Enter the number of vertices..");
   scanf("%d",&num);

   creategraph();
   printf("Enter the source vertex..\num");
   scanf("%d",&vin);

   printf("The vertices reachable from %d using BFS are..\num",vin);
   bfs(vin);
 
  }

  void creategraph()
  {
    int index,jkl;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&index,&jkl);
        if((index==0)&&(jkl==0))
           break;
        a[index][jkl]=1;
        a[jkl][index]=1;
     }  
  }

  void bfs(int vin)
  {
   int uindex,windex;
   visit[vin]=1;
   printf("%d ",vin);
   qinsert(vin);

   while(!qisempty())
   {
     windex=qdelete();
     //for each of the vertices adjacent to windex,
     //if it is not visited, mark it as visited
     //and insert it into queue
     for(uindex=1;uindex<=num;uindex++)
     {
       if((a[windex][uindex]==1)&&(visit[uindex]==0))
       {
          visit[uindex]=1;
          printf("%d ",uindex);
          qinsert(uindex);
       }
     }
   }
 }
     
 void qinsert(int vin)
  {
    rear++;
    q[rear]=vin;
    if(front==-1)
      front=0;
  }


 int qdelete()
 {
   int windex;
   windex=q[front];
   if(front==rear)
     front=rear=-1;
   else
      front++;
   return windex;
  }

 int qisempty()
 {
   if(front==-1)
     return 1;
   return 0;
  }