#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(char [], char [][10]);
int top=-1;
int main()
{
    char a[101][10], b[10], c[10];
    long i, j, num1, num2, k, l;
    char stack[101][10];
    i=0;
    while(scanf("%s", &a[i])==1)
    {
        
        i++;
    }
    for(j=0; j<i; j++)
    {
        if((a[j][0]>=48 && a[j][0]<=57) || (strcmp(a[j], "false")==0 || strcmp(a[j], "true")==0))
        {
            strcpy(b, a[j]);
            push(b, stack);
        }
        else if(a[j][0]=='*')
        {
            if(top<1)
            {
                printf("SYNTAX ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "false")==0 && (strcmp(stack[top-1], "false")!=0 && strcmp(stack[top-1], "and")!=0))
            {
                printf("TYPE ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "true")==0 && (strcmp(stack[top-1], "false")!=0 && strcmp(stack[top-1], "and")!=0))
            {
                printf("TYPE ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "false")==0 || strcmp(stack[top], "true")==0 || strcmp(stack[top-1], "false")==0 || strcmp(stack[top-1], "true")==0)
            {
                printf("TYPE ERROR");
                return 0;
            }
            else
            {
                num1=atoi(stack[top]);
                top--;
                num2=atoi(stack[top]);
                top--;
                num1=num1*num2;
                k=0;
                while(num1!=0)
                {
                    b[k]=num1%10+48;
                    k++;
                    num1/=10;
                }
                b[k]='\0';
                for(l=0; l<k; l++)
                {
                    c[l]=b[k-l-1];
                }
                c[k]='\0';
                push(c, stack);
                
            }
        }
        else if(a[j][0]=='+')
        {
            if(top<1)
            {
                printf("SYNTAX ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "false")==0 && (strcmp(stack[top-1], "false")!=0 && strcmp(stack[top-1], "and")!=0))
            {
                printf("TYPE ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "true")==0 && (strcmp(stack[top-1], "false")!=0 && strcmp(stack[top-1], "and")!=0))
            {
                printf("TYPE ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "false")==0 || strcmp(stack[top], "true")==0 || strcmp(stack[top-1], "false")==0 || strcmp(stack[top-1], "true")==0)
            {
                printf("TYPE ERROR");
                return 0;
            }
            else
            {
            num1=atoi(stack[top]);
                top--;
                num2=atoi(stack[top]);
                top--;
                num1=num1+num2;
                k=0;
                while(num1!=0)
                {
                    b[k]=num1%10+48;
                    k++;
                    num1/=10;
                }
                b[k]='\0';
                for(l=0; l<k; l++)
                {
                    c[l]=b[k-l-1];
                }
                c[k]='\0';
                push(c, stack);
            }
        }
        else if(a[j][0]=='=')
        {
            if(top<1)
            {
                printf("SYNTAX ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "false")==0 || strcmp(stack[top], "true")==0 || strcmp(stack[top-1], "false")==0 || strcmp(stack[top-1], "true")==0)
            {
                printf("TYPE ERROR");
                return 0;
            }
            else
            {
                if(strcmp(stack[top], stack[top-1])==0)
                {
                    top--;
                    strcpy(stack[top], "true");
                }
                else
                {
                    top--;
                    strcpy(stack[top], "false");
                }
            }
        }
        else if(strcmp(a[j], "and")==0)
        {
            if(top<1)
            {
                printf("SYNTAX ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "true")==0 || strcmp(stack[top], "false")==0)
            {
                if(strcmp(stack[top-1], "true")==0 || strcmp(stack[top-1], "false")==0)
                {
                    if(strcmp(stack[top], "true")==0 && strcmp(stack[top-1], "true")==0)
                    {
                        top-=2;
                        push("true", stack);
                    }
                    else
                    {
                        top-=2;
                        push("false", stack);
                    }
                }
                else
                {
                    printf("TYPE ERROR");
                    return 0;
                }
            }
            else
            {
                printf("TYPE ERROR");
                return 0;
            }
        }
        else
        {
            if(top<1)
            {
                printf("SYNTAX ERROR");
                return 0;
            }
            else if(strcmp(stack[top], "true")==0 || strcmp(stack[top], "false")==0)
            {
                if(strcmp(stack[top-1], "true")==0 || strcmp(stack[top-1], "false")==0)
                {
                    if(strcmp(stack[top], "true")==0 || strcmp(stack[top-1], "true")==0)
                    {
                        top-=2;
                        push("true", stack);
                    }
                    else
                    {
                        top-=2;
                        push("false", stack);
                    }
                }
                else
                {
                    printf("TYPE ERROR");
                    return 0;
                }
            }
            else
            {
                printf("TYPE ERROR");
                return 0;
            }
        }
        
    }
    if(top==0)
    {
        printf("%s", stack[top]);
    }
    else
    {
        printf("SYNTAX ERROR");
    }
}
 
void push(char a[], char stack[][10])
{
    top++;
    strcpy(stack[top], a);
}