#include <stdio.h>

int main(void) {
	// your code goes here

	int t;
	scanf("%d",&t);
	while(t--)
	{    int n;
	    scanf("%d",&n);
	    int a[n];
	    for(int i=0;i<n;i++)
	    scanf("%d",&a[i]);
	    int ChangedSpeed[n];
	    

//If front car is having less speed than the next car then the next car will have to lower its speed and make the speed equal to
//that of the front car in order to avoid collision
    
    int count=1;
	    for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                a[i]=a[i-1];
            else
               count++;


        }
        //Now comparing the array having maximum speeds and array having changed speeds
      


	    printf("%d\n",count);
	}




	return 0;
}



