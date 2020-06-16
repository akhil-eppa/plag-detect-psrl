#include<stdio.h>
#pragma pack(1)		// directive for the compiler to pack the structure
/*
#pragma pack(n)
where n is the alignment in bytes. Valid alignment values being 1, 2, 4 and 8. 
We will deal with only value 1

Used to force structures to match the spec-defined data layout. Pragma is implementation specific directive i.e each pragma directive has different implementation rule and use . There are many type of pragma directive and varies from one compiler to another compiler .If compiler does not recognize particular pragma, then it simply ignores that pragma statement without showing any error or warning message and execute the whole program assuming this pragma statement is not present. 
*/

//The size of the first structure is 5 bytes
struct new			
{
	int var1;
	char var2;
	
};		

//Size of test1 is also 5 bytes
struct new5
{
	char a;
	int b;
	
};
//Size of test2 is 6 bytes
struct str1
{
	char x;
	char Y;
	int Z;
	
};

//Size of test3 is 9 bytes
struct zero 
{
	int a1;
	char a2;
	int a5;
	
};
//Size of test4 is 10 bytes
struct str
{
	int f;
	char k;
	int e;
	char r;
	
};
int main()
{
	printf("size of the structure is %lu\n",sizeof(struct new));			//5		4+1
	printf("size of the structure is %lu\n",sizeof(struct new5));			//5		1+4
	printf("size of the structure is %lu\n",sizeof(struct str1));			//6		1+1+4
	printf("size of the structure is %lu\n",sizeof(struct zero));			//9		4+1+4
	printf("size of the structure is %lu\n",sizeof(struct str));			//10	4+1+4+1
	return 0;
}
