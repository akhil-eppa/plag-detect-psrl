//program to implement a simple queue
#include<stdlib.h>
#include<stdio.h>

int qinsert(int,int*,int*,int*,int);
 int qdelete(int *,int *, int*);
 void display(int *,int,int);
int main()
{
  
  int *qstar;
  int chx,k,xyz;
  int front,rear, length;
  front=rear=-1;
  printf("Enter the length of the queue..");
  scanf("%d",&length);

  qstar=malloc(sizeof(int)*length);
  while(1)
  {
    display(qstar,front,rear);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&chx);
    switch(chx)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&xyz);
              k=qinsert(xyz,qstar,&front,&rear,length);
              if(k>=0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=qdelete(qstar,&front,&rear);
              if(k>=0)
                printf("element deleted=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

 int qinsert(int xyz,int *qstar,int *front,int *rear,int length)
 {
   if(*rear==length-1)
   {
       printf("Queue full\n");
       return -1;
   }
    (*rear)++;
     qstar[*rear]=xyz;
     if(*front==-1)//first element
        *front=0;
  }

  int qdelete(int *qstar,int *front,int *rear)
  {
     int xyz;
    if(*front==-1)
    {
          printf("Queue empty..\n");
          return -1;
    }
    xyz=qstar[*front];
    if(*front==*rear)//only one element
     *front=*rear=-1;
    else
     (*front)++;
    return xyz;
  }

  void display(int *qstar,int front,int rear)
  {
    int index;
    if(front==-1)
      printf("Queue empty\n");
    else
      for(index=front;index<=rear;index++)
        printf("%d ",qstar[index]);
  }  