#include<stdio.h>
#include<stdlib.h>

struct tnode 
{
	char data;
	struct tnode *left;
	struct tnode *right;
};
struct tnode *create(char *exp);
int isoper(char ch);
void push(struct tnode **t,int *top, struct tnode *temp);
struct tnode *pop(struct tnode **stk, int *t);
void preorder(struct tnode *t);
void inorder(struct tnode *t);
void postorder(struct tnode *t);
int eval(struct tnode *t);
void main()
{
	struct tnode *root;
	root=NULL;
	char exp[100];
	
	printf("enter the expr in postfix\n");
	scanf("%s",exp);

	printf("CREATE EXPRESSION TREE\n");
	root=create(exp);

	printf("PREORDER\n");
	preorder(root);

	printf("INORDER\n");
	inorder(root);

	printf("POSTORDER\n");
	postorder(root);

	printf("evaluating expression\n");
	int result=eval(root);
	printf("after evaluation %d\n", result);



}
int eval(struct tnode *t)
{
	int x;
	switch(t->data)
	{
		case '+' : return(eval(t->left)+eval(t->right));
		case '-' : return(eval(t->left)-eval(t->right));
		case '*' : return(eval(t->left)*eval(t->right));
		case '/' : return(eval(t->left)/eval(t->right));
		case '%' : return(eval(t->left)%eval(t->right));
		default : printf("%c:", t->data);
			scanf("%d",&x);
			return x;
	}
}



struct tnode *create(char *exp)
{
	struct tnode *temp;
	struct tnode *stk[100];
	int i=0, top=-1;
	while(exp[i]!='\0')
	{
		char ch = exp[i];
		temp=(struct tnode *)malloc(sizeof(struct tnode));
		temp->data =ch;
		temp->left=temp->right=NULL;

		if(isoper(ch))
		{
			temp->right=pop(stk,&top);
			temp->left=pop(stk,&top);
			push(stk,&top,temp);
		}

		else
			push(stk,&top,temp);
			i++;
	}

		return pop(stk,&top);

}

int isoper(char ch)
{
	switch(ch)
		{
			case '+':
			case '-':
			case '*':
			case '%':
			case '/': return 1;
			default : return 0;
		}
}

void push(struct tnode **t,int *top, struct tnode *temp)
{
	++*top;
	t[*top]=temp;
	
}

struct tnode *pop(struct tnode **stk, int *t)
{
	struct tnode *temp;
	temp=stk[*t];
	--*t;
	return temp;
}

void preorder(struct tnode *t)
{
	if(t!=NULL)
	{
		printf("%c", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(struct tnode *t)
{
	if(t!=NULL)
	{
		inorder(t->left);		
		printf("%c", t->data);
		inorder(t->right);
	}
}

void postorder(struct tnode *t)
{
	if(t!=NULL)
	{
		postorder(t->left);		
		postorder(t->right);
		printf("%c", t->data);
	}
}



