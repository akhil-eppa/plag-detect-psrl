#include<stdio.h>
int main()
{
	long long int var1,var2,var3,var4,iter;
	long long int ans=0;
	scanf("%lld%lld%lld%lld",&var1,&var2,&var3,&var4);
	for(iter=var3;iter<=var4;iter++)
	{
		if(iter+2>=var1+var2)
			ans+=((iter-var1-var2+2)*(iter-var1-var2+1))/2;
		if(iter+2>=2*var2+1)
			ans-=((iter-2*var2+1)*(iter-2*var2))/2;
		if(iter+2>=var1+var3+1)
			ans-=((iter-var1-var3+1)*(iter-var1-var3))/2;
		if(iter-var2-var3>=0)
			ans+=((iter-var2-var3)*(iter-var2-var3-1))/2;
	}
	ans=(var2-var1+1)*(var3-var2+1)*(var4-var3+1)-ans;
	printf("%lld\n",ans);
}
