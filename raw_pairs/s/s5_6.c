#include <stdio.h>
#include <stdlib.h>
 
int task_option;
int amount, temp_amount;          //Amount of elements in the array
int index;
int temp;
int high,low;
int tasks;
int *next;
 
void bin_sort(int sort_array[], int n, int h, int l);
void right_insert(int sort_array[],int number, int location);
void left_insert(int sort_array[],int number, int location);
void add_to_all_tasks(int lookahead[],int all_tasks[], int temp_amount);
 
int main()
{
    //Get the amount of tasks
    scanf("%d",&tasks);
 
    //Initialize the array holding the tasks and a temp array with the lookahead characters
    int all_tasks[tasks];
    int lookahead[tasks];
    amount = 0;
 
    //before our first iteration we have to manually add the first element to temp_array
    task_option = 2;
    while(task_option == 2)
    {
        scanf("%d",&task_option);
        if(task_option == 1)
        {
            scanf("%d",&temp);
            *lookahead = temp;
            temp_amount = 1;
        }
 
        else
        {
            printf("Not enough enemies \n");
        }
 
        --tasks;
    }
 
    //Loop over the amount of tasks to be done
    int i;
    for(i = 0; i < tasks; i++)
    {
 
        scanf("%d",&task_option);
        if(task_option == 1)
        {
            scanf("%d",&temp);
            if(*lookahead == -1 || lookahead[temp_amount - 1] <= temp)
                lookahead[temp_amount++] = temp;
 
            else
            {
                add_to_all_tasks(lookahead,all_tasks,temp_amount);
                *lookahead = temp;
                temp_amount = 1;
            }
 
        }
 
        else if(task_option == 2)
        {
            add_to_all_tasks(lookahead,all_tasks,temp_amount);
 
            if(amount < 3)
            {
                printf("Not enough enemies\n");
                temp_amount = 0;
                *lookahead = -1;
                continue;
            }
 
            index = amount / 3 ;
            printf("%d\n",all_tasks[index - 1]);
 
            temp_amount = 0;
            *lookahead = -1;
 
        }
 
        else
            printf("Error with reading input\n");
    }
 
    return 0;
}
 
void bin_sort(int a[], int n,int h, int l)
{
 
    /*  int a[] is the array that we want to have sorted.
    *   int n is the number that is to be added into the array
    *   int h and l are the boundaries for the binary search.
    *   With this binary search we want to find the element(s) in between
    *   which our element can be placed.
    *   If the element doesn't exist we have either the right or left neighbor of our number
    *   If it's the Left neighbor then the number is greater than our number and we go to the right
    *   until we find a number not equal to the number found with the bin search, we move all elements
    *   a space to the right and insert our new number. We do the same just mirrored if the number is smaller
    */
 
    if(amount > 1)
    {
        if(l == h)
        {
            if(a[l] == n)
                right_insert(a,n,l);
 
            else
            {
                if(a[l] < n)
                    left_insert(a,n,l);
 
                else
                    right_insert(a,n,l);
            }
            return;
        }
 
        else
        {
            int median = (l + h) / 2;
            if(a[median] == n)
                right_insert(a,n,median);
            else
            {
                if(a[median] < n)
                {
                    h = median;
                    bin_sort(a,n,h,l);
                    return;
                }
 
                else
                {
                    l = median + 1;
                    bin_sort(a,n,h,l);
                    return;
                }
            }
            return;
        }
    }
 
    else
        *a = n;
    return;
}
 
void right_insert(int a[],int n, int loc)
{
    int temp_numb = a[loc];
    while(a[++loc] == temp_numb)
        continue;
 
    int i = amount;
 
    while(i > loc)
    {
        a[i--] = a[i-1];
    }
 
    a[loc] = n;
    return;
 
}
 
void left_insert(int a[],int n, int loc)
{
    int temp_numb = a[loc];
    while(a[--loc] == temp_numb && loc > -1)
        continue;
 
    int i = amount - 1;
 
    while(i > loc + 1)
    {
        a[i] = a[i-1];
        --i;
    }
 
    a[loc + 1] = n;
    return;
}
 
void add_to_all_tasks(int lookahead[],int a[],int temp_amount)
{
    next = &lookahead[temp_amount - 1];
 
    while(next >= lookahead)
    {
        amount++;
        bin_sort(a,*next,amount - 1,0);
        --next;
    }
 
}
 
