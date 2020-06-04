 #include<stdio.h>
 //bottom up technique
 //we are using the bottom up heap technique
  void bot_heap(int*,int);
  void top_heap(int *, int);
  
  int main()
  {
    int h[100];//heap structure
    int i,n;//n is the number of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);//accept the value of n
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
    //bot_heap(h,n-1);//index of the last element
   top_heap(h,n-1);//passing the index of last 
   printf("After creating heap..\n");//creating the heap
    for(i=0;i<n;i++)
      printf("%d ",h[i]);
   
  }

  void top_heap(int *h, int n)//n represents the last element
  {
    int i,j,k,key;

    for(k=1;k<=n;k++)//looping
    {
      i=k;
      key=h[i];

      j=(i-1)/2;
      
      //repeat till the value of key is greater than the parent
      //i=0 if the root is reached
      while((i>0)&&(key>h[j]))
      {
        h[i]=h[j];
        i=j;
        j=(i-1)/2;
      }
     h[i]=key;
   }
}     
void bot_heap(int *h, int n)//n indicates the last element
  {
   int i,j,k,key;

   for(k=(n-1)/2;k>=0;k--)//starting from last parent
   {
    j=k;
    key=h[j];
    
    i=2*j+1;//finding the index of left child of a node
    
    while(i<=n)//left child if exists
    {
      if((i+1)<=n)//right child if exists
      {
        if(h[i+1]>h[i]) //(REPLACING > WITH < WILL CREATE MIN HEAP)
         i++;//this will bring us the index of the largest child
      }
      if(key<h[i])
        {//(REPLACING < WITH > WILL CREATE MIN HEAP)
        h[j]=h[i];//moving the child up
        j=i;
        i=2*j+1;//getting the index of the left child
      }
     else
      break;
    }
   h[j]=key;
  }
}