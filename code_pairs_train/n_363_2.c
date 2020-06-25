#include<stdio.h>
main()
{ int t,n,k,i,j,s,q,a[30],b[30];
	scanf("%d",&t);
	while(t!=0) {
		scanf("%d%d",&n,&k); s=0;
		for(i=0; i<n; i++) scanf("%d",&a[i]);
		i=0;
		while(i<n){
			scanf("%d",&b[i]);
			++i;
		}
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if(a[i]>a[j]) {q=a[i]; a[i]=a[j]; a[j]=q;};
				if(b[i]<b[j]) {q=b[j]; b[j]=b[i]; b[i]=q;};	}};
		for(q=0;q!=k;++q)
			if(a[q]<b[q]) a[q]=b[q];
		i=0;
		while(i<n){
			s=s+a[i];
			i++;
		}
		printf("%d\n",s);
		t--;
	}
}
