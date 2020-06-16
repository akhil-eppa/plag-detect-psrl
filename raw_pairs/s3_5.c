#include<stdio.h>
#pragma pack(1)		// directive for the compiler to pack the structure
/*
#pragma pack(n)
where n is the alignment in bytes. Valid alignment values being 1, 2, 4 and 8. 
We will deal with only value 1

Used to force structures to match the spec-defined data layout. Pragma is implementation specific directive i.e each pragma directive has different implementation rule and use . There are many type of pragma directive and varies from one compiler to another compiler .If compiler does not recognize particular pragma, then it simply ignores that pragma statement without showing any error or warning message and execute the whole program assuming this pragma statement is not present. 
*/

//The size of the first structure is 5 bytes
typedef struct			
{
	int i;
	char j;
	
}test;		

//Size of test1 is also 5 bytes
typedef struct
{
	char j;
	int i;
	
}test1;
//Size of test2 is 6 bytes
typedef struct 
{
	char k;
	char j;
	int i;
	
}test2;

//Size of test3 is 9 bytes
typedef struct 
{
	int i;
	char k;
	int j;
	
}test3;
//Size of test4 is 10 bytes
typedef struct 
{
	int i;
	char k;
	int j;
	char d;
	
}test4;
int main()
{
    for(int i = 1; i<=5; i++)
    {
        switch(i)
        {
            case 1: printf("size of the structure is %lu\n",sizeof(test));			//5		4+1
                      break;
            case 2: printf("size of the structure is %lu\n",sizeof(test1));			//5		4+1
                      break;
            case 3: printf("size of the structure is %lu\n",sizeof(test2));			//5		4+1
                      break;
            case 4: printf("size of the structure is %lu\n",sizeof(test3));			//5		4+1
                      break;
            case 5: printf("size of the structure is %lu\n",sizeof(test4));			//5		4+1
                      break;
        }
    }
}
