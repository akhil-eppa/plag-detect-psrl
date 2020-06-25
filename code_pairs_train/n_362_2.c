#include<stdio.h>
main()
{ int t,n,k,i,j,s,q,a[30],b[30];
	scanf("%d",&t);
	while(t!=0) {
		scanf("%d%d",&n,&k); s=0;
		for(i=0; i<n; i++) scanf("%d",&b[i]);
		for(i=0; i<n; i++) scanf("%d",&a[i]);
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if(b[i]<b[j]) {q=b[j]; b[j]=b[i]; b[i]=q;};	}};
				if(a[i]>a[j]) {q=a[i]; a[i]=a[j]; a[j]=q;};
		q=0;
		while(q!=k) {
			if(a[q]<b[q]) a[q]=b[q]; q++;}
		for(i=0; i<n; i++) s=s+a[i];
		printf("%d\n",s);
		t--;
	}
}
