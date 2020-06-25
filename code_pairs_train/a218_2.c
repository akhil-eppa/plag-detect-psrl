#include <stdio.h>
void quicksort( int n, int A[])
{
    int j,key;
    for(int i=1;i<n;i++)
    {
        key=A[i];
        j=i-1;
        while(key<A[j] && j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main(void) 
{
int t,n,arrsongs[10000],i,j,pos,save,p;
scanf ("%d",&t);
for(i=1;i<=t;i++)
 {
   scanf ("%d",&n);
   
   for (j = 0; j<n ; j++)
   scanf ("%d",&arrsongs[j]);
   
   scanf ("%d",&pos);
   save = arrsongs[pos - 1];
   quicksort(n , &arrsongs[0]);
 
 for (p = 0 ; p<n ; p++)
  {
     if (save == arrsongs[p])
        {
	  printf ("%d\n", p + 1);
          break;
	}
  }
 }
return 0;
}	