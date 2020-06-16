#include<stdio.h>
#pragma pack(1)		// This is a directive for the compiler to pack the structure



struct test //5 bytes	
{
	int i;
	char j;
};		

struct test1 //5 bytes
{
	char j;
	int i;
	
};

struct test2 //6 bytes
{
	char k;
	char j;
	int i;
	
};


struct test3 //9 bytes
{
	int i;
	char k;
	int j;
	
};

struct test4 //10bytes
{
	int i;
	char k;
	int j;
	char d;
	
};
int main()
{
    //Displaying the sizes of each structure
	printf("size of the structure is %lu\n",sizeof(struct test));			//5		4+1
	printf("size of the structure is %lu\n",sizeof(struct test1));			//5		1+4
	printf("size of the structure is %lu\n",sizeof(struct test2));			//6		1+1+4
	printf("size of the structure is %lu\n",sizeof(struct test3));			//9		4+1+4
	printf("size of the structure is %lu\n",sizeof(struct test4));			//10	4+1+4+1
	return 0;
}
