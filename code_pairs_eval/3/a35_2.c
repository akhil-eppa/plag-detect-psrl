#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node* next;
    int data;
};
struct Node* head;
void Insert(int data,int n)
{
    struct Node* temp1=(struct Node*)(malloc(sizeof(struct Node)));
    temp1->next=NULL;
    temp1->data=data;
    struct Node* temp2=head;
    int i;
    if (n==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    for (i=0;i<n-2;i++)
    {
        temp2=temp2->next;//finally will point to (n-1)th node
    }
    temp1->next=temp2->next;//temp2->next points to nth node now which temp1 replaces
    temp2->next=temp1;
}
void Print()
{
    struct Node* temp=head;//temp variable is created to avoid changes to global variable head
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    head=NULL;
    Insert(4,2);
    Insert(5,1);
    Print();
    Insert(2,2);
    Insert(2,1);
    return 0;

}
