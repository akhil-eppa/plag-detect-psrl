#include<stdio.h>
#include<stdlib.h>
struct pqueue//implementing a queue
{
  int pty;//stores the priority number
  int data;//stores the data
};
//we can insert into the queue
void pqinsert(int,int,struct pqueue*,int*);
//delete from the priority queue
struct pqueue pqdelete(struct pqueue*,int*);
void qdisplay(struct pqueue*,int);
int main()
{
   //main function from where all the execution begins
   //all the user choices are made here
   //it calls all the helper functions 
  int k,ch,pty,x;
  struct pqueue pq[100];
  //structure
  struct pqueue temp;
  int count=0;
  while(1)
  {
    //this diplays the menu as required
    //user makes a choice
    qdisplay(pq,count);
    printf("\n1..insert");//to insert
    printf("\n2..remove");//to delete
    printf("\n3..display");//to display
    printf("\n4..EXIT");//to exit from the program
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the priority..");//we need to enter the priority
              
              scanf("%d",&pty);//pty
              printf("Enter the value");//then the value
              scanf("%d",&x);
              pqinsert(x,pty,pq,&count);
              
               break;
      case 2:temp=pqdelete(pq,&count);
              if(temp.data>0)
              {
                printf("deleted element:- data=%d",temp.data);
                printf("   priority=%d\n",temp.pty);
               }
              break;
        case 4:exit(0); 
   }
  }
 }
  struct pqueue pqdelete(struct pqueue *pq,int *count)//to delete something from the priority queue
  {
   int i;
   struct pqueue key;//this is the key
   if(*count==0)
   {
      key.data=0;
      key.pty=-1;
    }
    else
    {
    key=pq[0];
    for(i=1;i<=*count-1;i++)
      pq[i-1]=pq[i];
    (*count)--;
    }
   return key;//return it
  }
 void pqinsert(int x,int pty,struct pqueue *pq,int *count)//insert into the priority queue
 {
   int j;
   struct pqueue key;//structure
   key.data=x;
   key.pty=pty;//priority

   //pq[*count]=key;
   j=*count-1;

   while((j>=0)&&(pq[j].pty<key.pty))
   {
      pq[j+1]=pq[j];
      j--;
   }
   pq[j+1]=key;
   (*count)++;
 }
void qdisplay(struct pqueue *q, int count)//to diplay the queue structure
  {
    int i;
    if(count==0)
     printf("Empty Queue");//if queue is empty
   else
   {
    for(i=0;i<count;i++)//for loop
    {
      printf("\ndata = %d",q[i].data);//print data 
      printf("  pty=%d",q[i].pty);//print pty
      printf("\n");
    }  
  }
 }