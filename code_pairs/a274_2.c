
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,k,n,flag=0;
		scanf("%d %d %d %d",&x,&y,&k,&n);
		int p[n],c[n];
		for(int i=0;i<n;i++)
			scanf("%d %d",&p[i],&c[i]);
		for (int i = 0; i < n; ++i)
		{
			if((p[i]>=(x-y))&&(k>=c[i])){
				flag=1;
				printf("LuckyChef\n");
				break;
			}

		}
		if(flag==0)
			printf("UnluckyChef\n");

	}

	return 0;
}
	