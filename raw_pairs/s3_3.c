#include<stdio.h>
#pragma pack(1)		// directive for the compiler to pack the structure
/*
#pragma pack(n)
where n is the alignment in bytes. Valid alignment values being 1, 2, 4 and 8. 
We will deal with only value 1

Used to force structures to match the spec-defined data layout. Pragma is implementation specific directive i.e each pragma directive has different implementation rule and use . There are many type of pragma directive and varies from one compiler to another compiler .If compiler does not recognize particular pragma, then it simply ignores that pragma statement without showing any error or warning message and execute the whole program assuming this pragma statement is not present. 
*/

//Size of test3 is 9 bytes
struct test3 
{
    char k;
	
	
	int j;
    int i;
	
};

//The size of the first structure is 5 bytes
struct test			
{
    char j;
	int i;
};		

//Size of test4 is 10 bytes
struct test4
{
	int i;
	char k;
	int j;
	char d;
	
};


//Size of test2 is 6 bytes
struct test2
{
	char k;
	char j;
	int i;
	
};



//Size of test1 is also 5 bytes
struct test1
{
	char j;
	int i;
	
};



int main()
{
	printf("size of the structure is %lu\n",sizeof(struct test4));			//10	4+1+4+1
	printf("size of the structure is %lu\n",sizeof(struct test2));			//6		1+1+4
	printf("size of the structure is %lu\n",sizeof(struct test3));			//9		4+1+4
    printf("size of the structure is %lu\n",sizeof(struct test));			//5		4+1
	printf("size of the structure is %lu\n",sizeof(struct test1));			//5		1+4
    
	return 0;
}
