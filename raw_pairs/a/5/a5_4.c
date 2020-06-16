//program to implement a simple queue
#include<stdlib.h>
#include<stdio.h>

int qinsert(int,int*,int*,int*,int);//to insert into the queue
int qdelete(int *,int *, int*);//to delete an element from the queue
void display(int *,int,int);//to display elements in the queue
int main()
{
  //main function calls other functions from here
  int *q;//pointer
  int ch,k,x;
  int f,r, size;
  f=r=-1;//initial pointers are made -1
  printf("Enter the size of the queue..");//queue size accepted
  scanf("%d",&size);

  q=malloc(sizeof(int)*size);//dynamic memory allocation
  while(1)
  {
    display(q,f,r);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");//case 1
              scanf("%d",&x);
              k=qinsert(x,q,&f,&r,size);
              if(k>=0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=qdelete(q,&f,&r);//case 2
              if(k>=0)
                printf("element deleted=%d\n",k);
              break;
        case 4:exit(0); //otherwise
   }
  }
 }

 int qinsert(int x,int *q,int *f,int *r,int size)//insert an element into the queue
 {
   if(*r==size-1)//size
   {
       printf("Queue full\n");
       return -1;
   }
    (*r)++;
     q[*r]=x;
     if(*f==-1)//first element
        *f=0;
  }

  int qdelete(int *q,int *f,int *r)//this function is to delete an element from a queue
  {
     int x;
    if(*f==-1)//if empty
    {
          printf("Queue empty..\n");//printing
          return -1;
    }
    x=q[*f];
    if(*f==*r)//only one element
     *f=*r=-1;//making null
    else
     (*f)++;//increment
    return x;
  }

  void display(int *q,int f,int r)//displaying the queue as required
  {
    int i;
    if(f==-1)
      printf("Queue empty\n");//if empty just print as empty
    else
      for(i=f;i<=r;i++)//loop to print
        printf("%d ",q[i]);
  }  