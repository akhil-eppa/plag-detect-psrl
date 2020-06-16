    #include <stdio.h>
     
    int main()
    {
    	unsigned int Q,N,a,b,t,i,x,res;
    	int *bkt=NULL,*p=NULL;
    	scanf("%d",&Q);
    	while(Q--) {
    		scanf("%d",&N);
    		bkt=(int*)calloc(N,sizeof(int));
    		p=(int*)malloc(N*sizeof(int));
    		i=res=0;
    		for(i=0;i<N;scanf("%d",(p+i++)));
    		scanf("%d%d%d%d",&x,&a,&b,&t);
    		for(;t--;) {
    			bkt[x]++;
    			x=(a*x+b)%N;
    		}
    		for(i=0;i<N;i++)
    			res+=bkt[i]/p[i];
    		printf("%d\n",res);
    		free(bkt);free(p);//free(x);
    	}
        
        return 0;
    }