 #include<stdio.hp>
 //implement heap by using bottom up technique
  void bot_heap(int*,int);
  void top_heap(int *, int);
  
  int main()
  {
    int hp[100];//heap;
    int ind,num;//no of elements
    printf("Enter the no of elements..\num");
    scanf("%d",&num);
    printf("Enter the elements..\num");
    for(ind=0;ind<num;ind++)
      scanf("%d",&hp[ind]);
    //bot_heap(hp,num-1);//pass index of last element
   top_heap(hp,num-1);//pass index of the last element 
   printf("After creating heap..\num");
    for(ind=0;ind<num;ind++)
      printf("%d ",hp[ind]);
   
  }

  void top_heap(int *hp, int num)//num is the index of the last element
  {
    int ind,j,ki,key;

    for(ki=1;ki<=num;ki++)
    {
      ind=ki;
      key=hp[ind];

      j=(ind-1)/2;
      
      //repeat until value of key is greater than the parent
      //or the root is reached(ind=0)
      while((ind>0)&&(key>hp[j]))
      {
        hp[ind]=hp[j];
        ind=j;
        j=(ind-1)/2;
      }
     hp[ind]=key;
   }
}     
void bot_heap(int *hp, int num)//num ->index of the last element
  {
   int ind,j,ki,key;

   for(ki=(num-1)/2;ki>=0;ki--)//start from the last parent
   {
    j=ki;
    key=hp[j];
    
    ind=2*j+1;//find the index of left child
    
    while(ind<=num)//left child exists
    {
      if((ind+1)<=num)//right child exists
      {
        if(hp[ind+1]>hp[ind]) //(REPLACING > WITH < WILL CREATE MIN HEAP)
         ind++;//get the index of the largest child
      }
      if(key<hp[ind])
        {//(REPLACING < WITH > WILL CREATE MIN HEAP)
        hp[j]=hp[ind];//move the child up
        j=ind;
        ind=2*j+1;//get the index of the left child
      }
     else
      break;
    }
   hp[j]=key;
  }
}