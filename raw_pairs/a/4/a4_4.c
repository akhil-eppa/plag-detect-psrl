#include <stdio.h>
#include <stdlib.h>
/*
This is the structure of the node. A chain of nodes form a list
This is the basic building block of a linked list
*/
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;
//Insert is used to insert data into the linked list as specified
//We insert at the correct position based on user spec
void Insert(int data,int n)
{
    struct Node* temp1=(struct Node*)(malloc(sizeof(struct Node)));
    temp1->data=data;
    temp1->next=NULL;
    if (n==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    struct Node* temp2=head;
    int i;
    for (i=0;i<n-2;i++)
    {
        temp2=temp2->next;//finally will point to (n-1)th node, That is it will point to the last node
    }
    temp1->next=temp2->next;//temp2->next points to nth node now which temp1 replaces. Refer to the code
    temp2->next=temp1;
}
void Print()
{
    struct Node* temp=head;//temp variable is created to avoid changes to global variable head. Making changes to global variable could be catastrophic.
    while (temp!=NULL)
    {
        printf("%d ",temp->data);//printing out the content of the node as and when required. 
        temp=temp->next;//move to the next node.
    }
    printf("\n");
}
int main()
{
    head=NULL;
    //Elements to be inserted
    Insert(2,1);
    Insert(2,2);
    Insert(5,1);
    Insert(4,2);
    Print();
    return 0;

}
