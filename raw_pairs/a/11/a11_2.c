//program to implement quadratic probing
// if collision compute
// index=(hash(key)+i*i)%size for i=1,2,...tablesize
// hash(key)=key%size;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct element
{
   double key;
   char name[100];
   double mark;
};
void display(struct element *, double);
void insert_to_hash(struct element*, double,double, char*);
void delete_from_hash(struct element *,double ,double );
 
int main()
{
  struct element *hashtable;
  double i,n,ch,key,no_elements;
  char name[100];
  double tablesz;
  printf("Enter the table size..");
  scanf("%d",&tablesz);
  //create hash table
  hashtable=(struct element*)malloc(tablesz* sizeof(struct element));
   for(i=0;i<tablesz;i++)
     hashtable[i].mark=0;
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
      case 1: printf("Enter key..\n");
              scanf("%d",&key);
              printf("Enter name..\n");
              scanf("%s",name);
              insert_to_hash(hashtable,tablesz,key,name);
              break;
       case 2: printf("Enter the key for deletion..\n");
               scanf("%d",&key);
               delete_from_hash(hashtable,tablesz,key);
               break;
       /*case 3: printf("Enter the key to search..\n");
               scanf("%d",&key);
               search_in_hash(hashtable,tablesz,key);
               break;*/
        case 4:display(hashtable,tablesz);
    }
  }
 
}
 void delete_from_hash(struct element *ht,double size,double key )
  {
    double i,index,h;
    
    index=key %size;
     i=index;
     h=1;
     
     for(h=1;h<=size;h++)
     {
         if(ht[i].key==key)
        {
         printf("\nkey found..and deleted\n");
         ht[i].mark=0;
         return;
        }
       i=(index+h*h)%size;
      }
      printf("key not found\n");
    }
  void display(struct element *ht, double size)
  {
    double i;
    for(i=0;i<size;i++)
    {
      printf("%d :", i);
      if (ht[i].mark!=0)
         printf("Key = %d, name = %s",ht[i].key,ht[i].name);
      printf("\n");
    }
  }  
   void insert_to_hash(struct element*ht, double size,double key, char *name )
   {
     double index,i,h;
     index=key %size;
     i=index;
     //h=1;
     
     for(h=1;h<=size;h++)
     {
        if(ht[i].mark==0)
        {
         ht[i].key=key;
         strcpy(ht[i].name,name);
         ht[i].mark=1;
         return;
         }
       i=(index+h*h)%size;
      }
      printf("cannot insert..\n");
      return;
  }