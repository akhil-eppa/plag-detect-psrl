#include<stdio.h>
#include<string.h>
 
struct student			// type declaration which defines how student entity looks like
{						// now all three are related
	int rnum;			// these three are members of the structure
	char name[20];		
	int marks;
};			// semicolon is compulsory
//No memory allocation for declaration of the structure type

struct student s2;

int main()
{			 
	// all members are  uninitialized
	printf("%d-----------\n",s2.rnum);		// junk is printed
	// only one student details can be stored. If you want to store details of more students, we must create many structure variables separately or create array of structures
	strcpy(s2.name,"abc");
	s2.marks=78;
	s2.rnum=56;

	printf("%s\n",s2.name);
	printf("%d\n",s2.rnum);
	printf("%d\n",s2.marks);
	
	return 0;


}
