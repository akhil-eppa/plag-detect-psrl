//program to implement quadratic probing
// if collision compute
// index=(hash(key)+i*i)%sze for i=1,2,...tablesize
// hash(key)=key%sze;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct element
{
   int key;
   char name[100];
   int mark;
};
void display(struct element *, int);
void insert_to_hash(struct element*, int,int, char*);
void delete_from_hash(struct element *,int ,int );
 
int main()
{
  struct element *hashtable;
  int i,n,no_elements,ch,key;
  char name[100];
  printf("Enter the table sze..");
  int tablesz;
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
      case 2: printf("Enter the key for deletion..\n");
               scanf("%d",&key);
               delete_from_hash(hashtable,tablesz,key);
               break;
      case 1: printf("Enter key..\n");
              scanf("%d",&key);
              printf("Enter name..\n");
              scanf("%s",name);
              insert_to_hash(hashtable,tablesz,key,name);
              break;
       /*case 3: printf("Enter the key to search..\n");
               scanf("%d",&key);
               search_in_hash(hashtable,tablesz,key);
               break;*/
        case 4:display(hashtable,tablesz);
    }
  }
 
}
 void delete_from_hash(struct element *ht,int sze,int key )
  {
    int i,index,h;
    
    index=key %sze;
     i=index;
     h=1;
     
     for(h=1;h<=sze;h++)
     {
         if(ht[i].key==key)
        {
         printf("\nkey found..and deleted\n");
         ht[i].mark=0;
         return;
        }
       i=(index+h*h)%sze;
      }
      printf("key not found\n");
    }
  void display(struct element *ht, int sze)
  {
    int i;
    for(i=0;i<sze;i++)
    {
      printf("%d :", i);
      if (ht[i].mark!=0)
         printf("Key = %d, name = %s",ht[i].key,ht[i].name);
      printf("\n");
    }
  }  
   void insert_to_hash(struct element*ht, int sze,int key, char *name )
   {
     int index,i,h;
     index=key %sze;
     i=index;
     //h=1;
     
     for(h=1;h<=sze;h++)
     {
        if(ht[i].mark==0)
        {
         ht[i].key=key;
         strcpy(ht[i].name,name);
         ht[i].mark=1;
         return;
         }
       i=(index+h*h)%sze;
      }
      printf("cannot insert..\n");
      return;
  }