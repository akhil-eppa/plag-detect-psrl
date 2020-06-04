#include<stdio.h>
#include<math.h>
int main()
{
 int t,n,k,i,j,w1,w2,x1,x2,diff1,diff2,a[100],c,z;
 scanf("%d",&t);
 for(i=0;i<=t-1;i++){
    scanf("%d%d",&n,&z);
    for(j=0;j<=n-1;j++) scanf("%d",&a[j]);
    for(j=0;j<=n-1;j++){
        for(k=j+1;k<=n-1;k++){
            if(a[j]<a[k]){
                c=a[k];
                a[k]=a[j];
                a[j]=c;
            }
        }
    }
   // for(j=0;j<=n-1;j++) printf("%d\n",a[j]);
    w1=w2=0;
    for(j=0;j<=n-1;j++){
            if(j<=z-1) w1+=a[j];
            else w2+=a[j];}
   // printf("%d----w1\n",w1);
   // printf("%d----w2\n",w2);
    diff1=abs(w1-w2);
    x1=x2=0;
    for(j=0;j<=n-1;j++){
            if(j<=n-z-1) x1+=a[j];
            else x2+=a[j];}
    //printf("%d----x1\n",x1);
   // printf("%d----x2\n",x2);
    diff2=abs(x1-x2);
    if(diff1>diff2) printf("%d\n",diff1);
    else printf("%d\n",diff2);



 }
 return 0;
 }


