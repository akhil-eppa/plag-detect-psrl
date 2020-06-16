 #include <stdio.h>
 /*
 comments
    are
        added
            in
                this
                    code
                        */
void in(int *p)
{
    *p=0;register char ch=0; //register
    while(ch<'0' || ch>'9') //take only letters as input
        ch=getchar();
    while(ch>='0' && ch<='9'){ //if letter is a number, use getchar
        *p=(*p<<1)+(*p<<3)+ch-'0';
         ch=getchar();
    }
}
long int a[1000005]; //a is an array of type long int.
int main()
{
    //5 variables are declared here
    int i,j,t,l,r;
    in(&t); //in function
    for(i=2;i<=1000;i++){ //for loop runs 999 times
        if(a[i]!=0)continue; //continue
        for(j=i*i;j<1000003;j+=i){
            a[j]=1;
            //printf("Hello");
        }
    }
    //end of for
    for(i=2;i<1000003;i++){ //new for
        if(a[i]!=0)
        {
            a[i]=0;
        } //if-else condition
        else 
        {
            a[i]=i;
        }
    }
    for(i=3;i<1000003;i++){ //3rd for loop
        a[i]+=a[i-1];
    }
    //a[1] and a[0] are made 0.
    a[1]=0;
    a[0]=0;
    while(t--){ //for each test case,
        in(&l); //in left
        in(&r); //in right
        printf("%ld\n",a[r]-a[l-1]); //print final answer.
    }
    return 0;
}
//end of main