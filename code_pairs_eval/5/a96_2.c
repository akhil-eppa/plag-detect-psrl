//program to implement quadratic probing
// if collision compute
// index=(hash(keyx)+i*i)%size for i=1,2,...tablesize
// hash(keyx)=keyx%size;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct element
{
   int keyx;
   char nm[100];
   int mark;
};
void display(struct element *, int);
void insert_to_hash(struct element*, int,int, char*);
void delete_from_hash(struct element *,int ,int );
 
int main()
{
  struct element *htable;
  int i,n,ch,keyx,no_elements;
  char nm[100];
  int tablez;
  printf("Enter the table size..");
  scanf("%d",&tablez);
  //create hash table
  htable=(struct element*)malloc(tablez* sizeof(struct element));
   for(i=0;i<tablez;i++)
     htable[i].mark=0;
   no_elements=0;
  
  while(1)
  {
    printf("\n1. Insert..");
    printf("\n2. Delete..");
    printf("\n3. Search..");
    printf("\n4. Display..");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter keyx..\n");
              scanf("%d",&keyx);
              printf("Enter nm..\n");
              scanf("%s",nm);
              insert_to_hash(htable,tablez,keyx,nm);
              break;
       case 2: printf("Enter the keyx for deletion..\n");
               scanf("%d",&keyx);
               delete_from_hash(htable,tablez,keyx);
               break;
       /*case 3: printf("Enter the keyx to search..\n");
               scanf("%d",&keyx);
               search_in_hash(htable,tablez,keyx);
               break;*/
        case 4:display(htable,tablez);
    }
  }
 
}
 void delete_from_hash(struct element *ht,int size,int keyx )
  {
    int i,index,h;
    
    index=keyx %size;
     i=index;
     h=1;
     
     for(h=1;h<=size;h++)
     {
         if(ht[i].keyx==keyx)
        {
         printf("\nkey found..and deleted\n");
         ht[i].mark=0;
         return;
        }
       i=(index+h*h)%size;
      }
      printf("keyx not found\n");
    }
  void display(struct element *ht, int size)
  {
    int i;
    for(i=0;i<size;i++)
    {
      printf("%d :", i);
      if (ht[i].mark!=0)
         printf("Key = %d, nm = %s",ht[i].keyx,ht[i].nm);
      printf("\n");
    }
  }  
   void insert_to_hash(struct element*ht, int size,int keyx, char *nm )
   {
     int index,i,h;
     index=keyx %size;
     i=index;
     //h=1;
     
     for(h=1;h<=size;h++)
     {
        if(ht[i].mark==0)
        {
         ht[i].keyx=keyx;
         strcpy(ht[i].nm,nm);
         ht[i].mark=1;
         return;
         }
       i=(index+h*h)%size;
      }
      printf("cannot insert..\n");
      return;
  }