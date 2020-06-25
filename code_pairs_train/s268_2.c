#include <stdio.h>
#include <stdlib.h>
 
void print(int size,int start,int end,int *arr);
 
int main()
{
  short T;
  int N,M;
  long long K;
  int *A;
  long long sum=0;
  int index=0;
  int tempindex=index;
  int nosa=0;
 
 
  //printf("Enter no of test cases\n");
  scanf("%d",&T);
  while(T--)
  {
    //printf("Enter N,M and K\n");
    scanf("%d %d %lld",&N,&M,&K);
 
    A=malloc(sizeof(int)*N);
    //printf("Enter array elements\n");
 
    for(int i=0;i<N;++i)
    {
      scanf("%d",&A[i]);
    }
 
    index=0;
    nosa=0;
    while(index<=N*M)
    {
      //printf("Index no:%d\n",index);
      sum=A[index%N];
      tempindex=index+1;
      while(sum<=K && tempindex<=N*M)
      {
        //printf("Sum before is %d\n",sum);
        //printf("Sub-Array is:-\n\t\t");
        //print(N,index,tempindex-1,A);
 
        sum=sum+A[(tempindex)%N];
        tempindex++;
        nosa++;
        //printf("Sum after is %d\n",sum);
      }
      index++;
      //printf("\n");
    }
    printf("%d\n",nosa);
    free(A);
  }
  return 0;
}
 
void print(int size,int start,int end,int *arr)
{
 
  //printf("%d %d %d\n",start,end,size);
  for(int i=start;i<=end;++i)
    printf("%d ",arr[i%size]);
  printf("\n");
}