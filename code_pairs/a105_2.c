#include<stdio.h>
#include<stdlib.h>
struct pqueue
{
  int pt;
  int data;
};
void pqinsert(int,int,struct pqueue*,int*);
struct pqueue pqdelete(struct pqueue*,int*);
void qdisplay(struct pqueue*,int);
int main()
{
  int k,ch,pt,x;
  struct pqueue pq[100];
  
  struct pqueue temp;
  int cnt=0;
  while(1)
  {
    qdisplay(pq,cnt);
    printf("\n1..insert");
    printf("\n2..remove");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the priority..");
              
              scanf("%d",&pt);
              printf("Enter the value");
              scanf("%d",&x);
              pqinsert(x,pt,pq,&cnt);
              
               break;
      case 2:temp=pqdelete(pq,&cnt);
              if(temp.data>0)
              {
                printf("deleted element:- data=%d",temp.data);
                printf("   priority=%d\n",temp.pt);
               }
              break;
        case 4:exit(0); 
   }
  }
 }
  struct pqueue pqdelete(struct pqueue *pq,int *cnt)
  {
   int i_pt;
   struct pqueue keys;
   if(*cnt==0)
   {
      keys.data=0;
      keys.pt=-1;
    }
    else
    {
    keys=pq[0];
    for(i_pt=1;i_pt<=*cnt-1;i_pt++)
      pq[i_pt-1]=pq[i_pt];
    (*cnt)--;
    }
   return keys;
  }
 void pqinsert(int x,int pt,struct pqueue *pq,int *cnt)
 {
   int j;
   struct pqueue keys;
   keys.data=x;
   keys.pt=pt;

   //pq[*cnt]=keys;
   j=*cnt-1;

   while((j>=0)&&(pq[j].pt<keys.pt))
   {
      pq[j+1]=pq[j];
      j--;
   }
   pq[j+1]=keys;
   (*cnt)++;
 }
void qdisplay(struct pqueue *q, int cnt)
  {
    int i_pt;
    if(cnt==0)
     printf("Empty Queue");
   else
   {
    for(i_pt=0;i_pt<cnt;i_pt++)
    {
      printf("\ndata = %d",q[i_pt].data);
      printf("  pt=%d",q[i_pt].pt);
      printf("\n");
    }  
  }
 }