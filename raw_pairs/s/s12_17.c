#include <stdio.h>
int is_prime(int a)
{
	if(a==0||a==1)
		return 0;
	for(int i=2;i*i<=a;i++)
		if(a%i==0)
			return 0;
	return 1;
}
 
int main(void)
{
	long unsigned int arr[1000001],i,temp,l,r,q;
	arr[0] = 0;
	for(i=1;i<1000001;i++)
	{
		arr[i] = arr[i-1];
 
		if(is_prime(i))
		{
			arr[i]+= i;
		}
	}
	scanf("%lu",&q);
	while(q--)
	{
		scanf("%lu%lu",&l,&r);
		temp = arr[r]-arr[l];
		if(is_prime(l))
			temp+=l;
		printf("%lu\n",temp);
 
	}
 
}