#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node* link;
};
struct Node* point;
void Insert(int value,int num)
{
    struct Node* temper1=(struct Node*)(malloc(sizeof(struct Node)));
    temper1->value=value;
    temper1->link=NULL;
    if (num==1)
    {
        temper1->link=point;
        point=temper1;
        return;
    }
    struct Node* temp2=point;
    int i;
    for (i=0;i<num-2;i++)
    {
        temp2=temp2->link;//finally will point to (num-1)th node
    }
    temper1->link=temp2->link;//temp2->link points to nth node now which temper1 replaces
    temp2->link=temper1;
}
void Print()
{
    struct Node* temper=point;//temper variable is created to avoid changes to global variable point
    while (temper!=NULL)
    {
        printf("%d ",temper->value);
        temper=temper->link;
    }
    printf("\num");
}
int main()
{
    point=NULL;
    Insert(2,1);
    Insert(2,2);
    Insert(5,1);
    Insert(4,2);
    Print();
    return 0;

}
