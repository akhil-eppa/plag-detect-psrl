#include<stdio.h>
#include<math.h>
 
void main()
{
        int t,i,j,sum = 0,n,k,c,l,a[100000],t2;
        scanf("%d",&t);
        for(i=1;i<=t;i++)
        {
                scanf("%d",&n);
                c = 0;
                l = 1;
                if(n <= 5)
                {
                        k = 1;
                }
                else
                {
                        k = n * 4;
                }
                for(;;k++)
                {
                        sum = 0;
                        {
                                if(k / 5 > 0)
                                        sum += k/5;
                                if(k / 25 > 0)
                                        sum += k/25;
                                if(k / 125 > 0)
                                        sum += k/125;
                                if(k / 625 > 0)
                                        sum += k/625;
                                if(k /pow(5,5) > 0)
                                        sum += k/pow(5,5);
                                if(k / pow(5,6) > 0)
                                        sum += k / pow(5,6);
                                if(k / pow(5,7) > 0)
                                        sum += k  / pow(5,7);
                                if(k / pow(5,8) > 0)
                                        sum += k / pow(5,8);
                        }
                        if(sum == n)
                        {
                                t2 = k;
                                printf("5\n");
                printf("%d %d %d %d %d\n",t2,t2+1,t2+2,t2 + 3,t2 + 4);
                                break;
 
                        }
                        else if(sum > n)
                        {
                                printf("0\n");
                                break;
                        }
                }
                //printf("%d\n",c);
                //printf("%d %d %d %d %d",t2,t2+1,t2+2,t2 + 3,t2 + 4);
        }
}