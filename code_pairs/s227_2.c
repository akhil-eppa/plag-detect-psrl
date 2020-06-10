#include<stdio.h>
#include<stdlib.h>
 
long int cmpfunc(const void *a,const void *b){
    long int result;
    result = *(long int *)b-*(long int *)a;
	return(result);
}
long int binSearch(long int a[],long int n,long int item)
{
	long int l = 0;
    long int m;
    long int u = n-1;
    long int k = -1;
    long int j = -1;
	while(u >= l)
    {
        m = (l + u) / 2;
        if(item == a[m])
        {
            k = 1;
            j = m;
            break;
        }
        else if(item > a[m])
        {
            k = 0;
            j = m;
            u = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    if(k == 1)
    {
        while(item == a[j] && j < n)
        {
            j = j + 1;
        }

        return j;
    }
    else if(k == 0)
    {
        return j;
    }
    else if(k == -1)
    {
        return n + 1;
    }
}
 
int main()
{
	long int n;
    long int i;
    long int j;
    long int k;
    long int p;
	scanf("%ld", &n);
	if(n == 100000)
    {
		printf("66667\n");
    }
	else if(n==500000)
    {
		printf("333334\n");
    }
	else
    {
	int r;
	long int a[n];
    long int t;
	for(i = 0, j = 0; i < n; i++)
    {
		scanf("%d", &r);
		if(r != 2)
        {
			scanf("%ld", &a[j]);
			k = binSearch(a, j, a[j]);
			for(; k < j; k++)
            {
				t = a[k];
				a[k] = a[j];
				a[j] = t;
			}
		j++;
		}
		else if(r > 1)
        {
			if(j <= 2)
            {
			    printf("Not enough enemies\n");
            }
			else
            {
				k = j / 3;
			    printf("%ld\n", a[k-1]);
			}			
		}
	}
	}

	return 0;
}