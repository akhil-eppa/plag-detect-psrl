#include<stdio.h>
#pragma pack(1)		// directive for the compiler to pack the structure
/*
#pragma pack(n)
where n is the alignment in bytes. Valid alignment values being 1, 2, 4 and 8. 
We will deal with only value 1

Used to force structures to match the spec-defined data layout. Pragma is implementation specific directive i.e each pragma directive has different implementation rule and use . There are many type of pragma directive and varies from one compiler to another compiler .If compiler does not recognize particular pragma, then it simply ignores that pragma statement without showing any error or warning message and execute the whole program assuming this pragma statement is not present. 
*/

//The size of the first structure is 5 bytes
struct test			
{
	int i;
	char j;
};		

//Size of test1 is also 5 bytes
struct test1
{
	char j;
	int i;
	
};
//Size of test2 is 6 bytes
struct test2
{
	char k;
	char j;
	int i;
	
};

//Size of test3 is 9 bytes
struct test3 
{
	int i;
	char k;
	int j;
	
};
//Size of test4 is 10 bytes
struct test4
{
	int i;
	char k;
	int j;
	char d;
	
};
int main()
{
    struct test t;
    struct test1 t1;
    struct test2 t2;
    struct test3 t3;
    struct test4 t4;
	printf("size of the structure is %lu\n",sizeof(t));			//5		4+1
	printf("size of the structure is %lu\n",sizeof(t1));			//5		1+4
	printf("size of the structure is %lu\n",sizeof(t2));			//6		1+1+4
	printf("size of the structure is %lu\n",sizeof(t3));			//9		4+1+4
	printf("size of the structure is %lu\n",sizeof(t4));			//10	4+1+4+1
	return 0;
}