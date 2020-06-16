#include<stdio.h>
#pragma pack(1)
struct test			
{
	int i;
	char j;
};		
struct test1
{
	char j;
	int i;
};
struct test2
{
	char k;
	char j;
	int i;	
};
struct test3 
{
	int i;
	char k;
	int j;	
};
struct test4
{
	int i;
	char k;
	int j;
	char d;	
};
int main()
{
	printf("size of the structure is %lu\n",sizeof(struct test));
	printf("size of the structure is %lu\n",sizeof(struct test1));			
	printf("size of the structure is %lu\n",sizeof(struct test2));	
	printf("size of the structure is %lu\n",sizeof(struct test3));			
	printf("size of the structure is %lu\n",sizeof(struct test4));
	return 0;
}